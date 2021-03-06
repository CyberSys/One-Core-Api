@ stdcall AcceptSecurityContext(ptr ptr ptr long long ptr ptr ptr ptr)
@ stdcall AcquireCredentialsHandleA(str str long ptr ptr ptr ptr ptr ptr)
@ stdcall AcquireCredentialsHandleW(wstr wstr long ptr ptr ptr ptr ptr ptr)
@ stdcall AddCredentialsA(ptr str str long ptr ptr ptr ptr)
@ stdcall AddCredentialsW(ptr wstr wstr long ptr ptr ptr ptr)
@ stdcall AddSecurityPackageA(str ptr)
@ stdcall AddSecurityPackageW(wstr ptr)
@ stdcall ApplyControlTokenA(ptr ptr)
@ stdcall ApplyControlToken(ptr ptr) ApplyControlTokenW
@ stdcall CompleteAuthToken(ptr ptr)
@ stdcall CredMarshalTargetInfo(ptr ptr ptr)
@ stdcall CredUnmarshalTargetInfo(long long long long)
@ stdcall DecryptMessage(ptr ptr long ptr)
@ stdcall DeleteSecurityContext(ptr)
@ stdcall DeleteSecurityPackageA(str)
@ stdcall DeleteSecurityPackageW(wstr)
@ stdcall EncryptMessage(ptr long ptr long)
@ stdcall EnumerateSecurityPackagesA(ptr ptr)
@ stdcall EnumerateSecurityPackagesW(ptr ptr)
@ stdcall ExportSecurityContext(ptr long ptr ptr)
@ stdcall FreeContextBuffer(ptr)
@ stdcall FreeCredentialsHandle(ptr)
@ stdcall GetComputerObjectNameA(long ptr ptr)
@ stdcall GetComputerObjectNameW(long ptr ptr)
@ stdcall GetSecurityUserInfo(ptr long ptr)
@ stdcall GetUserNameExA(long ptr ptr)
@ stdcall GetUserNameExW(long ptr ptr)
@ stdcall ImpersonateSecurityContext(ptr)
@ stdcall ImportSecurityContextA(str ptr ptr ptr)
@ stdcall ImportSecurityContextW(wstr ptr ptr ptr)
@ stdcall InitSecurityInterfaceA()
@ stdcall InitSecurityInterfaceW()
@ stdcall InitializeSecurityContextA(ptr ptr str long long long ptr long ptr ptr ptr ptr)
@ stdcall InitializeSecurityContextW(ptr ptr wstr long long long ptr long ptr ptr ptr ptr)
@ stdcall LsaCallAuthenticationPackage(long long ptr long ptr ptr ptr)
@ stdcall LsaConnectUntrusted(long)
@ stdcall LsaDeregisterLogonProcess(long)
@ stdcall LsaEnumerateLogonSessions(ptr ptr)
@ stdcall LsaFreeReturnBuffer(ptr)
@ stdcall LsaGetLogonSessionData(ptr ptr)
@ stdcall LsaLogonUser(ptr ptr long long ptr long ptr ptr ptr ptr ptr ptr ptr ptr)
@ stdcall LsaLookupAuthenticationPackage(ptr ptr ptr)
@ stdcall LsaRegisterLogonProcess(ptr ptr ptr)
@ stdcall LsaRegisterPolicyChangeNotification(long ptr)
@ stdcall LsaUnregisterPolicyChangeNotification(long ptr)
@ stdcall MakeSignature(ptr long ptr long)
@ stdcall QueryContextAttributesA(ptr long ptr)
@ stdcall QueryContextAttributesW(ptr long ptr)
@ stdcall QueryCredentialsAttributesA(ptr long ptr)
@ stdcall QueryCredentialsAttributesW(ptr long ptr)
@ stdcall QuerySecurityContextToken(ptr ptr)
@ stdcall QuerySecurityPackageInfoA(str ptr)
@ stdcall QuerySecurityPackageInfoW(wstr ptr)
@ stdcall RevertSecurityContext(ptr)
@ stdcall SaslAcceptSecurityContext(ptr ptr ptr long long ptr ptr long ptr)
@ stdcall SaslEnumerateProfilesA(str ptr)
@ stdcall SaslEnumerateProfilesW(wstr ptr)
@ stdcall SaslGetContextOption(ptr long ptr long ptr)
@ stdcall SaslGetProfilePackageA(str ptr)
@ stdcall SaslGetProfilePackageW(wstr ptr)
@ stdcall SaslIdentifyPackageA(ptr ptr)
@ stdcall SaslIdentifyPackageW(ptr ptr)
@ stdcall SaslInitializeSecurityContextA(ptr ptr str long long long ptr long ptr ptr long ptr)
@ stdcall SaslInitializeSecurityContextW(ptr ptr wstr long long long ptr long ptr ptr long ptr)
@ stdcall SaslSetContextOption(ptr long ptr long long)
@ stdcall SealMessage(ptr long ptr long) EncryptMessage
@ stdcall SecCacheSspiPackages()
@ stdcall SecDeleteUserModeContext(ptr)
@ stdcall SecInitUserModeContext(ptr ptr)
@ stdcall SecpFreeMemory(ptr)
@ stdcall SecpSetIPAddress(ptr long)
@ stdcall SecpTranslateName(ptr wstr long long long long)
@ stdcall SecpTranslateNameEx(ptr wstr long long long long)
@ stdcall SetContextAttributesA(ptr long ptr long)
@ stdcall SetContextAttributesW(ptr long ptr long)
@ stdcall SetCredentialsAttributesA(ptr long ptr long)
@ stdcall SetCredentialsAttributesW(ptr long ptr long)
@ stdcall TranslateNameA(str long long ptr ptr)
@ stdcall TranslateNameW(wstr long long ptr ptr)
@ stdcall UnsealMessage(ptr ptr long ptr) DecryptMessage
@ stdcall VerifySignature(ptr ptr long ptr)

#Only on XP x64
@ stub -arch=x86_64 SupportsChannelBinding