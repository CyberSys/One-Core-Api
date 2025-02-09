@ stdcall CallNtPowerInformation (long ptr long ptr long)
@ stdcall CanUserWritePwrScheme ()
@ stdcall DeletePwrScheme (long)
@ stdcall EnumPwrSchemes (ptr long)
@ stdcall GetActivePwrScheme (ptr)
@ stdcall GetCurrentPowerPolicies (ptr ptr)
@ stdcall GetPwrCapabilities (ptr)
@ stdcall GetPwrDiskSpindownRange (ptr ptr)
@ stdcall IsAdminOverrideActive (ptr)
@ stdcall IsPwrHibernateAllowed ()
@ stdcall IsPwrShutdownAllowed ()
@ stdcall IsPwrSuspendAllowed ()
@ stdcall PowerGetActiveScheme (ptr ptr)
@ stdcall PowerReadACValue (ptr ptr ptr ptr ptr ptr ptr)
@ stdcall PowerReadDCValue (ptr ptr ptr ptr ptr ptr ptr)
@ stdcall ReadGlobalPwrPolicy (ptr)
@ stdcall ReadProcessorPwrScheme (long ptr)
@ stdcall ReadPwrScheme (long ptr)
@ stdcall SetActivePwrScheme (long ptr ptr)
@ stdcall SetSuspendState (long long long)
@ stdcall WriteGlobalPwrPolicy (ptr)
@ stdcall WriteProcessorPwrScheme (long ptr)
@ stdcall WritePwrScheme (ptr str str ptr)
@ stdcall ValidatePowerPolicies (ptr ptr)


@ stub PowerSetActiveScheme
@ stub PowerSettingRegisterNotification
@ stub PowerSettingUnregisterNotification
@ stub PowerWriteACValueIndex
@ stub PowerWriteDCValueIndex
@ stub PowerDeterminePlatformRoleEx
@ stdcall -stub PowerDeterminePlatformRole()