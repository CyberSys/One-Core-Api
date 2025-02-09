/*++

Copyright (c) 2024 Shorthorn Project

Module Name:

    istream.c

Abstract:

    This module implements Win32 Shell IStream Interface Functions

Author:

    Skulltrail 10-September-2024

Revision History:

--*/

#include <stdarg.h>
#include <assert.h>

#include "windef.h"
#include "winbase.h"
#include "winnls.h"
#include "winreg.h"
#include "objbase.h"
#include "shlguid.h"
#include "shlobj.h"
#include "shlwapi.h"
#include "wine/unicode.h"
#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(shlwapi);

struct AssocPerceivedInfo
{
    PCWSTR Type;
    PERCEIVED Perceived;
    INT FlagHardcoded;
    INT FlagSoftcoded;
    PCWSTR Extensions;
};

static const WCHAR unspecified_exts[] = {
    '.','l','n','k',0,
    '.','s','e','a','r','c','h','-','m','s',0,
    0
};

static const WCHAR image_exts[] = {
    '.','b','m','p',0,
    '.','d','i','b',0,
    '.','e','m','f',0,
    '.','g','i','f',0,
    '.','i','c','o',0,
    '.','j','f','i','f',0,
    '.','j','p','e',0,
    '.','j','p','e','g',0,
    '.','j','p','g',0,
    '.','p','n','g',0,
    '.','r','l','e',0,
    '.','t','i','f',0,
    '.','t','i','f','f',0,
    '.','w','m','f',0,
    0
};

static const WCHAR audio_exts[] = {
    '.','a','i','f',0,
    '.','a','i','f','c',0,
    '.','a','i','f','f',0,
    '.','a','u',0,
    '.','m','3','u',0,
    '.','m','i','d',0,
    '.','m','i','d','i',0,
#if _WIN32_WINNT > 0x602
    '.','m','p','2',0,
#endif
    '.','m','p','3',0,
    '.','r','m','i',0,
    '.','s','n','d',0,
    '.','w','a','v',0,
    '.','w','a','x',0,
    '.','w','m','a',0,
    0
};

static const WCHAR video_exts[] = {
    '.','a','s','f',0,
    '.','a','s','x',0,
    '.','a','v','i',0,
    '.','d','v','r','-','m','s',0,
    '.','I','V','F',0,
    '.','m','1','v',0,
#if _WIN32_WINNT <= 0x602
    '.','m','p','2',0,
#endif
    '.','m','p','2','v',0,
    '.','m','p','a',0,
    '.','m','p','e',0,
    '.','m','p','e','g',0,
    '.','m','p','g',0,
    '.','m','p','v','2',0,
    '.','w','m',0,
    '.','w','m','v',0,
    '.','w','m','x',0,
    '.','w','v','x',0,
    0
};

static const WCHAR compressed_exts[] = {
    '.','z','i','p',0,
    0
};

static const WCHAR document_exts[] = {
#if _WIN32_WINNT >= 0x600
    '.','h','t','m',0,
    '.','h','t','m','l',0,
#endif
    '.','m','h','t',0,
    0
};

static const WCHAR system_exts[] = {
    '.','c','p','l',0,
    0
};

static const WCHAR application_exts[] = {
    '.','b','a','s',0,
    '.','b','a','t',0,
    '.','c','m','d',0,
    '.','c','o','m',0,
    '.','e','x','e',0,
    '.','h','t','a',0,
    '.','m','s','i',0,
    '.','p','i','f',0,
    '.','r','e','g',0,
    '.','s','c','r',0,
    '.','v','b',0,
    0
};

const WCHAR type_text[] = {'t','e','x','t',0};
const WCHAR type_image[] = {'i','m','a','g','e',0};
const WCHAR type_audio[] = {'a','u','d','i','o',0};
const WCHAR type_video[] = {'v','i','d','e','o',0};
const WCHAR type_compressed[] = {'c','o','m','p','r','e','s','s','e','d',0};
const WCHAR type_document[] = {'d','o','c','u','m','e','n','t',0};
const WCHAR type_system[] = {'s','y','s','t','e','m',0};
const WCHAR type_application[] = {'a','p','p','l','i','c','a','t','i','o','n',0};

#define HARDCODED_NATIVE_WMSDK      (PERCEIVEDFLAG_HARDCODED | PERCEIVEDFLAG_NATIVESUPPORT | PERCEIVEDFLAG_WMSDK)
#define HARDCODED_NATIVE_GDIPLUS    (PERCEIVEDFLAG_HARDCODED | PERCEIVEDFLAG_NATIVESUPPORT | PERCEIVEDFLAG_GDIPLUS)
#define HARDCODED_NATIVE_ZIPFLDR    (PERCEIVEDFLAG_HARDCODED | PERCEIVEDFLAG_NATIVESUPPORT | PERCEIVEDFLAG_ZIPFOLDER)
#define SOFTCODED_NATIVESUPPORT     (PERCEIVEDFLAG_SOFTCODED | PERCEIVEDFLAG_NATIVESUPPORT)

static const struct AssocPerceivedInfo known_types[] = {
    { NULL,             PERCEIVED_TYPE_UNSPECIFIED, PERCEIVEDFLAG_HARDCODED,  PERCEIVEDFLAG_SOFTCODED, unspecified_exts },
    { type_text,        PERCEIVED_TYPE_TEXT,        PERCEIVEDFLAG_HARDCODED,  SOFTCODED_NATIVESUPPORT, NULL },
    { type_image,       PERCEIVED_TYPE_IMAGE,       HARDCODED_NATIVE_GDIPLUS, PERCEIVEDFLAG_SOFTCODED, image_exts },
    { type_audio,       PERCEIVED_TYPE_AUDIO,       HARDCODED_NATIVE_WMSDK,   PERCEIVEDFLAG_SOFTCODED, audio_exts },
    { type_video,       PERCEIVED_TYPE_VIDEO,       HARDCODED_NATIVE_WMSDK,   PERCEIVEDFLAG_SOFTCODED, video_exts },
    { type_compressed,  PERCEIVED_TYPE_COMPRESSED,  HARDCODED_NATIVE_ZIPFLDR, PERCEIVEDFLAG_SOFTCODED, compressed_exts },
    { type_document,    PERCEIVED_TYPE_DOCUMENT,    PERCEIVEDFLAG_HARDCODED,  PERCEIVEDFLAG_SOFTCODED, document_exts },
    { type_system,      PERCEIVED_TYPE_SYSTEM,      PERCEIVEDFLAG_HARDCODED,  PERCEIVEDFLAG_SOFTCODED, system_exts },
    { type_application, PERCEIVED_TYPE_APPLICATION, PERCEIVEDFLAG_HARDCODED,  PERCEIVEDFLAG_SOFTCODED, application_exts },
};

static const struct AssocPerceivedInfo* AssocFindByBuiltinExtension(LPCWSTR pszExt)
{
    UINT n;
    for (n = 0; n < sizeof(known_types) / sizeof(known_types[0]); ++n)
    {
        PCWSTR Ext = known_types[n].Extensions;
        while (Ext && *Ext)
        {
            if (!StrCmpIW(Ext, pszExt))
                return &known_types[n];
            Ext += (strlenW(Ext) + 1);
        }
    }
    return NULL;
}

static const struct AssocPerceivedInfo* AssocFindByType(LPCWSTR pszType)
{
    UINT n;
    for (n = 0; n < sizeof(known_types) / sizeof(known_types[0]); ++n)
    {
        if (known_types[n].Type)
        {
            if (!StrCmpIW(known_types[n].Type, pszType))
                return &known_types[n];
        }
    }
    return NULL;
}

/*************************************************************************
 * AssocGetPerceivedType  [SHLWAPI.@]
 *
 * Detect the type of a file by inspecting its extension
 *
 * PARAMS
 *  lpszExt     [I] File extension to evaluate.
 *  lpType      [O] Pointer to perceived type
 *  lpFlag      [O] Pointer to perceived type flag
 *  lppszType   [O] Address to pointer for perceived type text
 *
 * RETURNS
 *  Success: S_OK. lpType and lpFlag contain the perceived type and
 *           its information. If lppszType is not NULL, it will point
 *           to a string with perceived type text.
 *  Failure: An HRESULT error code indicating the error.
 *
 * NOTES
 *  lppszType is optional and it can be NULL.
 *  if lpType or lpFlag are NULL, the function will crash.
 *  if lpszExt is NULL, an error is returned.
 */
HRESULT WINAPI AssocGetPerceivedType(LPCWSTR lpszExt, PERCEIVED *lpType,
                                     INT *lpFlag, LPWSTR *lppszType)
{
    static const WCHAR PerceivedTypeKey[] = {'P','e','r','c','e','i','v','e','d','T','y','p','e',0};
    static const WCHAR SystemFileAssociationsKey[] = {'S','y','s','t','e','m','F','i','l','e',
        'A','s','s','o','c','i','a','t','i','o','n','s','\\','%','s',0};
    const struct AssocPerceivedInfo *Info;

    TRACE("(%s,%p,%p,%p)\n", debugstr_w(lpszExt), lpType, lpFlag, lppszType);

    Info = AssocFindByBuiltinExtension(lpszExt);
    if (Info)
    {
        *lpType = Info->Perceived;
        *lpFlag = Info->FlagHardcoded;
    }
    else
    {
        WCHAR Buffer[100] = { 0 };
        DWORD Size = sizeof(Buffer);
        if (RegGetValueW(HKEY_CLASSES_ROOT, lpszExt, PerceivedTypeKey,
                         RRF_RT_REG_SZ, NULL, Buffer, &Size) == ERROR_SUCCESS)
        {
            Info = AssocFindByType(Buffer);
        }
        if (!Info)
        {
            WCHAR KeyName[MAX_PATH] = { 0 };
            snprintfW(KeyName, MAX_PATH, SystemFileAssociationsKey, lpszExt);
            Size = sizeof(Buffer);
            if (RegGetValueW(HKEY_CLASSES_ROOT, KeyName, PerceivedTypeKey,
                             RRF_RT_REG_SZ, NULL, Buffer, &Size) == ERROR_SUCCESS)
            {
                Info = AssocFindByType(Buffer);
            }
        }
        if (Info)
        {
            *lpType = Info->Perceived;
            *lpFlag = Info->FlagSoftcoded;
        }
    }

    if (Info)
    {
        if (lppszType && Info->Type)
        {
            return SHStrDupW(Info->Type, lppszType);
        }
        return Info->Type ? S_OK : E_FAIL;
    }
    else
    {
        *lpType = PERCEIVED_TYPE_UNSPECIFIED;
        *lpFlag = 0;
    }
    return HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND);
}