// header for LoadLibraly
//	
//	TOWERAPI.H
//	
//	Header file for the LEGO USB Tower API. It contains the prototypes of the functions exported
//	by TOWERAPI.DLL
//	
//	Written by AS
//	Copyright (C) 1999 The LEGO Group. All rights reserved.
//	
//	@doc
//	
#ifndef __TOWERAPI_H__

	#define __TOWERAPI_H__

	#if _MSC_VER > 1000
		#pragma once
	#endif // _MSC_VER > 1000

	#ifdef TOWERAPI_EXPORTS
	#else
	#endif

	//	Driver request codes
	//	
 #include "legousbtowerioctl.h"

	//	-------------------------------------------------------------------------------
	//	Structure definition.
	//	
	//	Definition of structure types used as parameters to towerapi functions ONLY. 
	//	
	//	Other LT_xxx structures which are also used as parameters to LEGOTower IoControl
	//	requests are defined in legousbtowerioctl.h (included above) or in vendreq.h.
	//	

	//	
	//	Configuration parameters
	//	
	typedef struct LT_CONFIG {

		//	size of the structure. It must be always initialized when passing this structure 
		//	to LEGOTowerSet/GetDefaultConfig
		//	
		DWORD dwsize;	

		DWORD dwrange;					// a LT_RANGE_xxx constant
		DWORD dwlink;					// a LT_LINK_xxx constant

		// if set to TRUE, enables long range transmission but requires a high-power USB plug
		//	
		BOOL  fhighpower;	

		//	Timeouts
		//	
		DWORD dwtimeout_read_1st;		// first byte timeout
		DWORD dwtimeout_read_ic;		// intercharacter timeout
		DWORD dwtimeout_write;			// write timeout

		//	Read buffer size
		//	
		DWORD dwbuffersize;

	}LT_CONFIG, *PLT_CONFIG;

	//	-------------------------------------------------------------------------------
	//	Function prototypes
	//	

	#ifdef __cplusplus
		extern "C" {
	#endif

typedef BOOL (CALLBACK* _LEGOTowerSetRange) (HANDLE hdevice, WORD wrange);
typedef BOOL (CALLBACK* _LEGOTowerGetRange) (HANDLE hdevice, WORD *pwrange);

typedef BOOL (CALLBACK* _LEGOTowerSetLinkMode) (HANDLE hdevice, WORD wlinkmode);
typedef BOOL (CALLBACK* _LEGOTowerGetLinkMode) (HANDLE hdevice, WORD *pwlinkmode);

typedef BOOL (CALLBACK* _LEGOTowerSetEndianness) ( HANDLE hdevice, WORD wendianness );
typedef BOOL (CALLBACK* _LEGOTowerGetEndianness) ( HANDLE hdevice, WORD *pwendianness );

typedef BOOL (CALLBACK* _LEGOTowerFlush) (HANDLE hdevice, WORD wflags); 
typedef BOOL (CALLBACK* _LEGOTowerReset) (HANDLE hdevice);

typedef BOOL (CALLBACK* _LEGOTowerSetTimeouts) (HANDLE hdevice, DWORD dwread_first, DWORD dwread_ic, DWORD dwwrite );
typedef BOOL (CALLBACK* _LEGOTowerGetTimeouts) (HANDLE hdevice, DWORD *pdwread_first, DWORD *pdwread_ic, DWORD *pdwwrite );

typedef BOOL (CALLBACK* _LEGOTowerGetCaps)  ( HANDLE hdevice, DWORD dwcaps, LT_CAPS *pcaps );
typedef BOOL (CALLBACK* _LEGOTowerGetVersion)  ( HANDLE hdevice, PLT_VERSION pver );
typedef BOOL (CALLBACK* _LEGOTowerGetCopyright)  ( HANDLE hdevice, LPTSTR lpszbuffer, size_t size );
typedef BOOL (CALLBACK* _LEGOTowerGetCredits)  ( HANDLE hdevice, LPTSTR lpszbuffer, size_t size );

typedef BOOL (CALLBACK* _LEGOTowerGetLedMode) (HANDLE hdevice, BYTE *pwledmode);
typedef BOOL (CALLBACK* _LEGOTowerSetLedMode) (HANDLE hdevice, BYTE wledmode);

typedef BOOL (CALLBACK* _LEGOTowerGetLedState) (HANDLE hdevice, BYTE bledid, BYTE *pbcolor);
typedef BOOL (CALLBACK* _LEGOTowerSetLedState) (HANDLE hdevice, BYTE bledid, BYTE bnewcolor);

typedef BOOL (CALLBACK* _LEGOTowerGetIRSpeed) ( HANDLE hdevice, WORD *pwtxspeed, WORD *pwrxspeed );
typedef BOOL (CALLBACK* _LEGOTowerSetIRSpeed) (HANDLE hdevice, WORD wtxspeed, WORD wrxspeed );

typedef BOOL (CALLBACK* _LEGOTowerResetCommStats) ( HANDLE hdevice );
typedef BOOL (CALLBACK* _LEGOTowerGetCommStats) (HANDLE hdevice, PLT_COMMSTATS pstats );

typedef BOOL (CALLBACK* _LEGOTowerSetDefaultConfig) ( LT_CONFIG *pltcfg );
typedef BOOL (CALLBACK* _LEGOTowerGetDefaultConfig) ( LT_CONFIG *pltcfg );
typedef BOOL (CALLBACK* _LEGOTowerGetFactoryConfig) ( LT_CONFIG *pltcfg );

typedef BOOL (CALLBACK* _LEGOTowerGetErrorState) ( HANDLE hdevice, WORD *pwerror );
typedef BOOL (CALLBACK* _LEGOTowerGetState) ( HANDLE hdevice, WORD *pwtowerstate );

typedef DWORD (CALLBACK* _LEGOTowerGetWin32Error) ( WORD wtowererror );

typedef BOOL (CALLBACK* _LEGOTowerSetCarrierFrequency) ( HANDLE hdevice, WORD wfrequency );
typedef BOOL (CALLBACK* _LEGOTowerGetCarrierFrequency) ( HANDLE hdevice, WORD *pwfrequency );

typedef BOOL (CALLBACK* _LEGOTowerSetCarrierDutyCycle) ( HANDLE hdevice, WORD wrange, WORD wdutycycle );
typedef BOOL (CALLBACK* _LEGOTowerGetCarrierDutyCycle) ( HANDLE hdevice, WORD wrange, WORD *pwdutycycle );

		//	 
		//	Functions specific for IRC protocol fine-tuning
		//	
typedef BOOL (CALLBACK* _LEGOTowerSetIRCParm) ( HANDLE hdevice, BYTE bparmcode, BYTE barg, WORD windex );
typedef BOOL (CALLBACK* _LEGOTowerGetIRCParm) ( HANDLE hdevice, BYTE bparmcode, BYTE *pbvalue );

typedef BOOL (CALLBACK* _LEGOTowerSetIRCTimeFrame) ( HANDLE hdevice, BYTE btimeframe ); 
typedef BOOL (CALLBACK* _LEGOTowerGetIRCTimeFrame) ( HANDLE hdevice, BYTE *pbtimeframe );

typedef BOOL (CALLBACK* _LEGOTowerSetIRCPacketSize) ( HANDLE hdevice, BYTE bpacketsize ); 
typedef BOOL (CALLBACK* _LEGOTowerGetIRCPacketSize) ( HANDLE hdevice, BYTE *pbpacketsize );

typedef BOOL (CALLBACK* _LEGOTowerRestart) ( HANDLE hdevice );
typedef BOOL (CALLBACK* _LEGOTowerRestartAll) ( void );

typedef BOOL (CALLBACK* _LEGOTowerReenumerateAll) ( void );
typedef BOOL (CALLBACK* _LEGOTowerIsUSBEnabled) ( void );

		//	Diagnostic Functions
		//	
		#define SZBUF_FRIENDLYNAME		128
		#define SZBUF_PROVIDERNAME		128
		#define SZBUF_DRIVERNAME		260
		#define SZBUF_DRIVERVER			64
		#define SZBUF_DEVICEPATH		MAX_PATH		

		typedef void *HTOWERINFO;

		typedef struct LT_TOWERPNPINFO 
		{
			//	Tower information
			//	
			DWORD	dwaddr;					// USB ADDRESS
			DWORD	dwstatus;				// Device status

			DWORD	dwconnected;			// the tower is currently connected
			DWORD	dwproblem;				// Problem id
			DWORD	dwordinal;				// tower ordinal number (NOT NECESSARILY the x in the \\.\LEGOTOWERx symlink)

			TCHAR	szfriendlyname[SZBUF_FRIENDLYNAME];
			TCHAR	szdevpath[SZBUF_DEVICEPATH];

			//	Parent hub information
			//	
			struct {

				BOOL	fbuspowered;					// TRUE if bus powered
				DWORD	dwaddr;							// USB Address
				
				TCHAR	szfriendlyname[SZBUF_FRIENDLYNAME];

			}parenthub;

			//	Driver information
			//	
			struct {

				TCHAR	szdriverver[SZBUF_DRIVERVER];
				TCHAR   szdrivername[SZBUF_DRIVERNAME];
				TCHAR   szprovidername[SZBUF_PROVIDERNAME];

			}driver;

		} LT_TOWERPNPINFO, *PLT_TOWERPNPINFO;

		
		typedef struct LT_HCINFO 
		{
			DWORD dwhcerror;	// if couldn't open the controller this field points to the error code

			TCHAR szdevicekeyname[SZBUF_DRIVERNAME];
			TCHAR szdevicedesc[SZBUF_FRIENDLYNAME];

		}LT_HCINFO, *PLT_HCINFO;

		// -------------------------------------------------------------------------
		// Device status flags (duplicated from the DDK header file cfg.h -- added LT prefix)
		//
		#define LTDN_ROOT_ENUMERATED (0x00000001) // Was enumerated by ROOT
		#define LTDN_DRIVER_LOADED   (0x00000002) // Has Register_Device_Driver
		#define LTDN_ENUM_LOADED     (0x00000004) // Has Register_Enumerator
		#define LTDN_STARTED         (0x00000008) // Is currently configured
		#define LTDN_MANUAL          (0x00000010) // Manually installed
		#define LTDN_NEED_TO_ENUM    (0x00000020) // May need reenumeration
		#define LTDN_NOT_FIRST_TIME  (0x00000040) // Has received a config
		#define LTDN_HARDWARE_ENUM   (0x00000080) // Enum generates hardware ID
		#define LTDN_LIAR            (0x00000100) // Lied about can reconfig once
		#define LTDN_HAS_MARK        (0x00000200) // Not CM_Create_DevInst lately
		#define LTDN_HAS_PROBLEM     (0x00000400) // Need device installer
		#define LTDN_FILTERED        (0x00000800) // Is filtered
		#define LTDN_MOVED           (0x00001000) // Has been moved
		#define LTDN_DISABLEABLE     (0x00002000) // Can be rebalanced
		#define LTDN_REMOVABLE       (0x00004000) // Can be removed
		#define LTDN_PRIVATE_PROBLEM (0x00008000) // Has a private problem
		#define LTDN_MF_PARENT       (0x00010000) // Multi function parent
		#define LTDN_MF_CHILD        (0x00020000) // Multi function child
		#define LTDN_WILL_BE_REMOVED (0x00040000) // DevInst is being removed

		//
		// Windows 4 OPK2 Flags
		//
		#define LTDN_NOT_FIRST_TIMEE  0x00080000  // S: Has received a config enumerate
		#define LTDN_STOP_FREE_RES    0x00100000  // S: When child is stopped, free resources
		#define LTDN_REBAL_CANDIDATE  0x00200000  // S: Don't skip during rebalance
		#define LTDN_BAD_PARTIAL      0x00400000  // S: This devnode's log_confs do not have same resources
		#define LTDN_NT_ENUMERATOR    0x00800000  // S: This devnode's is an NT enumerator
		#define LTDN_NT_DRIVER        0x01000000  // S: This devnode's is an NT driver

		//
		// Windows 4.1 Flags
		//
		#define LTDN_NEEDS_LOCKING    0x02000000  // S: Devnode need lock resume processing
		#define LTDN_ARM_WAKEUP       0x04000000  // S: Devnode can be the wakeup device
		#define LTDN_APM_ENUMERATOR   0x08000000  // S: APM aware enumerator
		#define LTDN_APM_DRIVER       0x10000000  // S: APM aware driver
		#define LTDN_SILENT_INSTALL   0x20000000  // S: Silent install
		#define LTDN_NO_SHOW_IN_DM    0x40000000  // S: No show in device manager
		#define LTDN_BOOT_LOG_PROB    0x80000000  // S: Had a problem during preassignment of boot log conf

		// -------------------------------------------------------------------------
		// Device problem flags (duplicated from the DDK header file cfg.h -- added LT prefix)
		//
		#define LTCM_PROB_NOT_CONFIGURED         (0x00000001)   // no config for device
		#define LTCM_PROB_DEVLOADER_FAILED       (0x00000002)   // service load failed
		#define LTCM_PROB_OUT_OF_MEMORY          (0x00000003)   // out of memory
		#define LTCM_PROB_ENTRY_IS_WRONG_TYPE    (0x00000004)   //
		#define LTCM_PROB_LACKED_ARBITRATOR      (0x00000005)   //
		#define LTCM_PROB_BOOT_CONFIG_CONFLICT   (0x00000006)   // boot config conflict
		#define LTCM_PROB_FAILED_FILTER          (0x00000007)   //
		#define LTCM_PROB_DEVLOADER_NOT_FOUND    (0x00000008)   // Devloader not found
		#define LTCM_PROB_INVALID_DATA           (0x00000009)   //
		#define LTCM_PROB_FAILED_START           (0x0000000A)   //
		#define LTCM_PROB_LIAR                   (0x0000000B)   //
		#define LTCM_PROB_NORMAL_CONFLICT        (0x0000000C)   // config conflict
		#define LTCM_PROB_NOT_VERIFIED           (0x0000000D)   //
		#define LTCM_PROB_NEED_RESTART           (0x0000000E)   // requires restart
		#define LTCM_PROB_REENUMERATION          (0x0000000F)   //
		#define LTCM_PROB_PARTIAL_LOG_CONF       (0x00000010)   //
		#define LTCM_PROB_UNKNOWN_RESOURCE       (0x00000011)   // unknown res type
		#define LTCM_PROB_REINSTALL              (0x00000012)   //
		#define LTCM_PROB_REGISTRY               (0x00000013)   //
		#define LTCM_PROB_VXDLDR                 (0x00000014)   // WINDOWS 95 ONLY
		#define LTCM_PROB_WILL_BE_REMOVED        (0x00000015)   // devinst will remove
		#define LTCM_PROB_DISABLED               (0x00000016)   // devinst is disabled
		#define LTCM_PROB_DEVLOADER_NOT_READY    (0x00000017)   // Devloader not ready
		#define LTCM_PROB_DEVICE_NOT_THERE       (0x00000018)   // device doesn't exist
		#define LTCM_PROB_MOVED                  (0x00000019)   //
		#define LTCM_PROB_TOO_EARLY              (0x0000001A)   //
		#define LTCM_PROB_NO_VALID_LOG_CONF      (0x0000001B)   // no valid log config
		#define LTCM_PROB_FAILED_INSTALL         (0x0000001C)   // install failed
		#define LTCM_PROB_HARDWARE_DISABLED      (0x0000001D)   // device disabled
		#define LTCM_PROB_CANT_SHARE_IRQ         (0x0000001E)   // can't share IRQ
		#define LTCM_PROB_FAILED_ADD             (0x0000001F)   // driver failed add
		#define LTCM_PROB_DISABLED_SERVICE       (0x00000020)   // service's Start = 4
		#define LTCM_PROB_TRANSLATION_FAILED     (0x00000021)   // resource translation failed
		#define LTCM_PROB_NO_SOFTCONFIG          (0x00000022)   // no soft config
		#define LTCM_PROB_BIOS_TABLE             (0x00000023)   // device missing in BIOS table
		#define LTCM_PROB_IRQ_TRANSLATION_FAILED (0x00000024)   // IRQ translator failed
		#define NUM_LTCM_PROB                    (0x00000025)


		/*
		typedef struct LT_USBPNPINFO 
		{
			BOOL	finstalled;				// USB Support installed

			DWORD	dwnumcontrollers;		// # of USB controllers
			DWORD	dwstatus;				// USB controller status 
			DWORD	dwproblem;				// Problem id

		} LT_USBPNPINFO, *PLT_USBPNPINFO;
		*/

		#define LTFIND_ALL			0x00	// finds all tower known to the system (even if not currently connected)
		#define LTFIND_CONNECTED	0x01	// finds only connected devices (working and not working)
		#define LTFIND_WORKING		0x02	// finds only working and connected devices

typedef HTOWERINFO (CALLBACK* _LEGOTowerFindFirst) ( DWORD dwfindfilter );
typedef BOOL (CALLBACK* _LEGOTowerFindNext) ( HTOWERINFO htower );
typedef BOOL (CALLBACK* _LEGOTowerFindPrev) ( HTOWERINFO htower );
										
typedef BOOL (CALLBACK* _LEGOTowerGetDeviceInfo) ( HTOWERINFO htower, PLT_TOWERPNPINFO ptowerinfo );
typedef BOOL (CALLBACK* _LEGOTowerFindStop) ( HTOWERINFO htower );

typedef LPCTSTR (CALLBACK* _LEGOTowerGetPathName) ( HTOWERINFO htower );
typedef BOOL (CALLBACK* _LEGOTowerGetPathNameCopy) ( HTOWERINFO htower, LPTSTR pszname, size_t size );

typedef BOOL (CALLBACK* _LEGOTowerGetProblemDesc) ( DWORD dwproblem, LPTSTR pszdesc, size_t size );

typedef BOOL (CALLBACK* _LEGOTowerGetDeviceInfoByNumber) ( DWORD dwdeviceno, 
																		DWORD				dwfindfilter,
																		PLT_TOWERPNPINFO	ppnpinfo		);

typedef BOOL (CALLBACK* _LEGOTowerGetHostControllerInfo) ( DWORD dwindex, PLT_HCINFO phcinfo );

	#ifdef __cplusplus
		};
	#endif

#endif
bool TowerInit();
void TowerClose();
_LEGOTowerSetRange LEGOTowerSetRange;
_LEGOTowerGetRange LEGOTowerGetRange;
_LEGOTowerSetLinkMode LEGOTowerSetLinkMode;
_LEGOTowerGetLinkMode LEGOTowerGetLinkMode;
_LEGOTowerSetEndianness LEGOTowerSetEndianness;
_LEGOTowerGetEndianness LEGOTowerGetEndianness;
_LEGOTowerFlush LEGOTowerFlush;
_LEGOTowerReset LEGOTowerReset;
_LEGOTowerSetTimeouts LEGOTowerSetTimeouts;
_LEGOTowerGetTimeouts LEGOTowerGetTimeouts;
_LEGOTowerGetCaps LEGOTowerGetCaps;
_LEGOTowerGetVersion LEGOTowerGetVersion;
_LEGOTowerGetCopyright LEGOTowerGetCopyright;
_LEGOTowerGetCredits LEGOTowerGetCredits;
_LEGOTowerGetLedMode LEGOTowerGetLedMode;
_LEGOTowerSetLedMode LEGOTowerSetLedMode;
_LEGOTowerGetLedState LEGOTowerGetLedState;
_LEGOTowerSetLedState LEGOTowerSetLedState;
_LEGOTowerGetIRSpeed LEGOTowerGetIRSpeed;
_LEGOTowerSetIRSpeed LEGOTowerSetIRSpeed;
_LEGOTowerResetCommStats LEGOTowerResetCommStats;
_LEGOTowerGetCommStats LEGOTowerGetCommStats;
_LEGOTowerSetDefaultConfig LEGOTowerSetDefaultConfig;
_LEGOTowerGetDefaultConfig LEGOTowerGetDefaultConfig;
_LEGOTowerGetFactoryConfig LEGOTowerGetFactoryConfig;
_LEGOTowerGetErrorState LEGOTowerGetErrorState;
_LEGOTowerGetState LEGOTowerGetState;
_LEGOTowerGetWin32Error LEGOTowerGetWin32Error;
_LEGOTowerSetCarrierFrequency LEGOTowerSetCarrierFrequency;
_LEGOTowerGetCarrierFrequency LEGOTowerGetCarrierFrequency;
_LEGOTowerSetCarrierDutyCycle LEGOTowerSetCarrierDutyCycle;
_LEGOTowerGetCarrierDutyCycle LEGOTowerGetCarrierDutyCycle;
_LEGOTowerSetIRCParm LEGOTowerSetIRCParm;
_LEGOTowerGetIRCParm LEGOTowerGetIRCParm;
_LEGOTowerSetIRCTimeFrame LEGOTowerSetIRCTimeFrame;
_LEGOTowerGetIRCTimeFrame LEGOTowerGetIRCTimeFrame;
_LEGOTowerSetIRCPacketSize LEGOTowerSetIRCPacketSize;
_LEGOTowerGetIRCPacketSize LEGOTowerGetIRCPacketSize;
_LEGOTowerRestart LEGOTowerRestart;
_LEGOTowerRestartAll LEGOTowerRestartAll;
_LEGOTowerReenumerateAll LEGOTowerReenumerateAll;
_LEGOTowerIsUSBEnabled LEGOTowerIsUSBEnabled;
_LEGOTowerFindFirst LEGOTowerFindFirst;
_LEGOTowerFindNext LEGOTowerFindNext;
_LEGOTowerFindPrev LEGOTowerFindPrev;
_LEGOTowerGetDeviceInfo LEGOTowerGetDeviceInfo;
_LEGOTowerFindStop LEGOTowerFindStop;
_LEGOTowerGetPathName LEGOTowerGetPathName;
_LEGOTowerGetPathNameCopy LEGOTowerGetPathNameCopy;
_LEGOTowerGetProblemDesc LEGOTowerGetProblemDesc;
_LEGOTowerGetDeviceInfoByNumber LEGOTowerGetDeviceInfoByNumber;
_LEGOTowerGetHostControllerInfo LEGOTowerGetHostControllerInfo;
