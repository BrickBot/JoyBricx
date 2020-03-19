static HINSTANCE hDLL;
bool TowerInit() {
	if ((hDLL = LoadLibrary("TowerApi.dll")) == (HINSTANCE)NULL) {
	return false;
}
LEGOTowerSetRange = (_LEGOTowerSetRange)GetProcAddress(hDLL, "LEGOTowerSetRange");
LEGOTowerGetRange = (_LEGOTowerGetRange)GetProcAddress(hDLL, "LEGOTowerGetRange");
LEGOTowerSetLinkMode = (_LEGOTowerSetLinkMode)GetProcAddress(hDLL, "LEGOTowerSetLinkMode");
LEGOTowerGetLinkMode = (_LEGOTowerGetLinkMode)GetProcAddress(hDLL, "LEGOTowerGetLinkMode");
LEGOTowerSetEndianness = (_LEGOTowerSetEndianness)GetProcAddress(hDLL, "LEGOTowerSetEndianness");
LEGOTowerGetEndianness = (_LEGOTowerGetEndianness)GetProcAddress(hDLL, "LEGOTowerGetEndianness");
LEGOTowerFlush = (_LEGOTowerFlush)GetProcAddress(hDLL, "LEGOTowerFlush");
LEGOTowerReset = (_LEGOTowerReset)GetProcAddress(hDLL, "LEGOTowerReset");
LEGOTowerSetTimeouts = (_LEGOTowerSetTimeouts)GetProcAddress(hDLL, "LEGOTowerSetTimeouts");
LEGOTowerGetTimeouts = (_LEGOTowerGetTimeouts)GetProcAddress(hDLL, "LEGOTowerGetTimeouts");
LEGOTowerGetCaps = (_LEGOTowerGetCaps)GetProcAddress(hDLL, "LEGOTowerGetCaps");
LEGOTowerGetVersion = (_LEGOTowerGetVersion)GetProcAddress(hDLL, "LEGOTowerGetVersion");
LEGOTowerGetCopyright = (_LEGOTowerGetCopyright)GetProcAddress(hDLL, "LEGOTowerGetCopyright");
LEGOTowerGetCredits = (_LEGOTowerGetCredits)GetProcAddress(hDLL, "LEGOTowerGetCredits");
LEGOTowerGetLedMode = (_LEGOTowerGetLedMode)GetProcAddress(hDLL, "LEGOTowerGetLedMode");
LEGOTowerSetLedMode = (_LEGOTowerSetLedMode)GetProcAddress(hDLL, "LEGOTowerSetLedMode");
LEGOTowerGetLedState = (_LEGOTowerGetLedState)GetProcAddress(hDLL, "LEGOTowerGetLedState");
LEGOTowerSetLedState = (_LEGOTowerSetLedState)GetProcAddress(hDLL, "LEGOTowerSetLedState");
LEGOTowerGetIRSpeed = (_LEGOTowerGetIRSpeed)GetProcAddress(hDLL, "LEGOTowerGetIRSpeed");
LEGOTowerSetIRSpeed = (_LEGOTowerSetIRSpeed)GetProcAddress(hDLL, "LEGOTowerSetIRSpeed");
LEGOTowerResetCommStats = (_LEGOTowerResetCommStats)GetProcAddress(hDLL, "LEGOTowerResetCommStats");
LEGOTowerGetCommStats = (_LEGOTowerGetCommStats)GetProcAddress(hDLL, "LEGOTowerGetCommStats");
LEGOTowerSetDefaultConfig = (_LEGOTowerSetDefaultConfig)GetProcAddress(hDLL, "LEGOTowerSetDefaultConfig");
LEGOTowerGetDefaultConfig = (_LEGOTowerGetDefaultConfig)GetProcAddress(hDLL, "LEGOTowerGetDefaultConfig");
LEGOTowerGetFactoryConfig = (_LEGOTowerGetFactoryConfig)GetProcAddress(hDLL, "LEGOTowerGetFactoryConfig");
LEGOTowerGetErrorState = (_LEGOTowerGetErrorState)GetProcAddress(hDLL, "LEGOTowerGetErrorState");
LEGOTowerGetState = (_LEGOTowerGetState)GetProcAddress(hDLL, "LEGOTowerGetState");
LEGOTowerGetWin32Error = (_LEGOTowerGetWin32Error)GetProcAddress(hDLL, "LEGOTowerGetWin32Error");
LEGOTowerSetCarrierFrequency = (_LEGOTowerSetCarrierFrequency)GetProcAddress(hDLL, "LEGOTowerSetCarrierFrequency");
LEGOTowerGetCarrierFrequency = (_LEGOTowerGetCarrierFrequency)GetProcAddress(hDLL, "LEGOTowerGetCarrierFrequency");
LEGOTowerSetCarrierDutyCycle = (_LEGOTowerSetCarrierDutyCycle)GetProcAddress(hDLL, "LEGOTowerSetCarrierDutyCycle");
LEGOTowerGetCarrierDutyCycle = (_LEGOTowerGetCarrierDutyCycle)GetProcAddress(hDLL, "LEGOTowerGetCarrierDutyCycle");
LEGOTowerSetIRCParm = (_LEGOTowerSetIRCParm)GetProcAddress(hDLL, "LEGOTowerSetIRCParm");
LEGOTowerGetIRCParm = (_LEGOTowerGetIRCParm)GetProcAddress(hDLL, "LEGOTowerGetIRCParm");
LEGOTowerSetIRCTimeFrame = (_LEGOTowerSetIRCTimeFrame)GetProcAddress(hDLL, "LEGOTowerSetIRCTimeFrame");
LEGOTowerGetIRCTimeFrame = (_LEGOTowerGetIRCTimeFrame)GetProcAddress(hDLL, "LEGOTowerGetIRCTimeFrame");
LEGOTowerSetIRCPacketSize = (_LEGOTowerSetIRCPacketSize)GetProcAddress(hDLL, "LEGOTowerSetIRCPacketSize");
LEGOTowerGetIRCPacketSize = (_LEGOTowerGetIRCPacketSize)GetProcAddress(hDLL, "LEGOTowerGetIRCPacketSize");
LEGOTowerRestart = (_LEGOTowerRestart)GetProcAddress(hDLL, "LEGOTowerRestart");
LEGOTowerRestartAll = (_LEGOTowerRestartAll)GetProcAddress(hDLL, "LEGOTowerRestartAll");
LEGOTowerReenumerateAll = (_LEGOTowerReenumerateAll)GetProcAddress(hDLL, "LEGOTowerReenumerateAll");
LEGOTowerIsUSBEnabled = (_LEGOTowerIsUSBEnabled)GetProcAddress(hDLL, "LEGOTowerIsUSBEnabled");
LEGOTowerFindFirst = (_LEGOTowerFindFirst)GetProcAddress(hDLL, "LEGOTowerFindFirst");
LEGOTowerFindNext = (_LEGOTowerFindNext)GetProcAddress(hDLL, "LEGOTowerFindNext");
LEGOTowerFindPrev = (_LEGOTowerFindPrev)GetProcAddress(hDLL, "LEGOTowerFindPrev");
LEGOTowerGetDeviceInfo = (_LEGOTowerGetDeviceInfo)GetProcAddress(hDLL, "LEGOTowerGetDeviceInfo");
LEGOTowerFindStop = (_LEGOTowerFindStop)GetProcAddress(hDLL, "LEGOTowerFindStop");
LEGOTowerGetPathName = (_LEGOTowerGetPathName)GetProcAddress(hDLL, "LEGOTowerGetPathName");
LEGOTowerGetPathNameCopy = (_LEGOTowerGetPathNameCopy)GetProcAddress(hDLL, "LEGOTowerGetPathNameCopy");
LEGOTowerGetProblemDesc = (_LEGOTowerGetProblemDesc)GetProcAddress(hDLL, "LEGOTowerGetProblemDesc");
LEGOTowerGetDeviceInfoByNumber = (_LEGOTowerGetDeviceInfoByNumber)GetProcAddress(hDLL, "LEGOTowerGetDeviceInfoByNumber");
LEGOTowerGetHostControllerInfo = (_LEGOTowerGetHostControllerInfo)GetProcAddress(hDLL, "LEGOTowerGetHostControllerInfo");
return true;
}
void TowerClose()
{
FreeLibrary(hDLL);
}
