@ stdcall ExpandEnvironmentStringsA(str ptr long) kernel32.ExpandEnvironmentStringsA
@ stdcall ExpandEnvironmentStringsW(wstr ptr long) kernel32.ExpandEnvironmentStringsW
@ stdcall FreeEnvironmentStringsA(ptr) kernel32.FreeEnvironmentStringsA
@ stdcall FreeEnvironmentStringsW(ptr) kernel32.FreeEnvironmentStringsW
@ stdcall GetCommandLineA() kernel32.GetCommandLineA
@ stdcall GetCommandLineW() kernel32.GetCommandLineW
@ stdcall GetCurrentDirectoryA(long ptr) kernel32.GetCurrentDirectoryA
@ stdcall GetCurrentDirectoryW(long ptr) kernel32.GetCurrentDirectoryW
@ stdcall GetEnvironmentStrings() kernel32.GetEnvironmentStrings
@ stdcall GetEnvironmentStringsW() kernel32.GetEnvironmentStringsW
@ stdcall GetEnvironmentVariableA(str ptr long) kernel32.GetEnvironmentVariableA
@ stdcall GetEnvironmentVariableW(wstr ptr long) kernel32.GetEnvironmentVariableW
@ stdcall GetStdHandle(long) kernel32.GetStdHandle
@ stdcall NeedCurrentDirectoryForExePathA(str) kernel32.NeedCurrentDirectoryForExePathA
@ stdcall NeedCurrentDirectoryForExePathW(wstr) kernel32.NeedCurrentDirectoryForExePathW
@ stdcall SearchPathA(str str str long ptr ptr) kernel32.SearchPathA
@ stdcall SearchPathW(wstr wstr wstr long ptr ptr) kernel32.SearchPathW
@ stdcall SetCurrentDirectoryA(str) kernel32.SetCurrentDirectoryA
@ stdcall SetCurrentDirectoryW(wstr) kernel32.SetCurrentDirectoryW
@ stdcall SetEnvironmentStringsA(ptr) kernel32.SetEnvironmentStringsA
@ stdcall SetEnvironmentStringsW(ptr) kernel32.SetEnvironmentStringsW
@ stdcall SetEnvironmentVariableA(str str) kernel32.SetEnvironmentVariableA
@ stdcall SetEnvironmentVariableW(wstr wstr) kernel32.SetEnvironmentVariableW
@ stdcall SetStdHandle(long long) kernel32.SetStdHandle
@ stdcall SetStdHandleEx(long ptr long) kernel32.SetStdHandleEx