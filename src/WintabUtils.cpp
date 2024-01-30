#include "WintabUtils.h"


HINSTANCE ghWintab = NULL;

WTINFOA gpWTInfoA = NULL;
WTINFOW gpWTInfoW = NULL;
WTOPENA gpWTOpenA = NULL;
WTOPENW gpWTOpenW = NULL;
WTGETA gpWTGetA = NULL;
WTGETW gpWTGetW = NULL;
WTSETA gpWTSetA = NULL;
WTSETW gpWTSetW = NULL;
WTCLOSE gpWTClose = NULL;
WTPACKET gpWTPacket = NULL;
WTENABLE gpWTEnable = NULL;
WTOVERLAP gpWTOverlap = NULL;
WTSAVE gpWTSave = NULL;
WTCONFIG gpWTConfig = NULL;
WTRESTORE gpWTRestore = NULL;
WTEXTSET gpWTExtSet = NULL;
WTEXTGET gpWTExtGet = NULL;
WTQUEUESIZESET gpWTQueueSizeSet = NULL;
WTDATAPEEK gpWTDataPeek = NULL;
WTPACKETSGET gpWTPacketsGet = NULL;
WTMGROPEN gpWTMgrOpen = NULL;
WTMGRCLOSE gpWTMgrClose = NULL;
WTMGRDEFCONTEXT gpWTMgrDefContext = NULL;
WTMGRDEFCONTEXTEX gpWTMgrDefContextEx = NULL;


//////////////////////////////////////////////////////////////////////////////
// Purpose
//		Find wintab32.dll and load it.
//		Find the exported functions we need from it.
//
//	Returns
//		TRUE on success.
//		FALSE on failure.
//////////////////////////////////////////////////////////////////////////////
BOOL LoadWintab(void)
{
	ghWintab = LoadLibraryA("Wintab32.dll");
	if (!ghWintab)
	{
		DWORD err = GetLastError();
		return FALSE;
	}

	// Explicitly find the exported Wintab functions in which we are interested.
	// We are using the ASCII, not Unicode versions (where applicable).
	gpWTOpenA = (WTOPENA)GetProcAddress(ghWintab, "WTOpenA");
	gpWTOpenW = (WTOPENW)GetProcAddress(ghWintab, "WTOpenW");
	gpWTInfoA = (WTINFOA)GetProcAddress(ghWintab, "WTInfoA");
	gpWTInfoW = (WTINFOW)GetProcAddress(ghWintab, "WTInfoW");
	gpWTGetA = (WTGETA)GetProcAddress(ghWintab, "WTGetA");
	gpWTGetW = (WTGETW)GetProcAddress(ghWintab, "WTGetW");
	gpWTSetA = (WTSETA)GetProcAddress(ghWintab, "WTSetA");
	gpWTSetW = (WTSETW)GetProcAddress(ghWintab, "WTSetW");
	gpWTPacket = (WTPACKET)GetProcAddress(ghWintab, "WTPacket");
	gpWTClose = (WTCLOSE)GetProcAddress(ghWintab, "WTClose");
	gpWTEnable = (WTENABLE)GetProcAddress(ghWintab, "WTEnable");
	gpWTOverlap = (WTOVERLAP)GetProcAddress(ghWintab, "WTOverlap");
	gpWTSave = (WTSAVE)GetProcAddress(ghWintab, "WTSave");
	gpWTConfig = (WTCONFIG)GetProcAddress(ghWintab, "WTConfig");
	gpWTRestore = (WTRESTORE)GetProcAddress(ghWintab, "WTRestore");
	gpWTExtSet = (WTEXTSET)GetProcAddress(ghWintab, "WTExtSet");
	gpWTExtGet = (WTEXTGET)GetProcAddress(ghWintab, "WTExtGet");
	gpWTQueueSizeSet = (WTQUEUESIZESET)GetProcAddress(ghWintab, "WTQueueSizeSet");
	gpWTDataPeek = (WTDATAPEEK)GetProcAddress(ghWintab, "WTDataPeek");
	gpWTPacketsGet = (WTPACKETSGET)GetProcAddress(ghWintab, "WTPacketsGet");
	gpWTMgrOpen = (WTMGROPEN)GetProcAddress(ghWintab, "WTMgrOpen");
	gpWTMgrClose = (WTMGRCLOSE)GetProcAddress(ghWintab, "WTMgrClose");
	gpWTMgrDefContext = (WTMGRDEFCONTEXT)GetProcAddress(ghWintab, "WTMgrDefContext");
	gpWTMgrDefContextEx = (WTMGRDEFCONTEXTEX)GetProcAddress(ghWintab, "WTMgrDefContextEx");

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////////
// Purpose
//		De-initializes use of wintab32.dll
//////////////////////////////////////////////////////////////////////////////
void UnloadWintab(void)
{
	if (ghWintab)
	{
		FreeLibrary(ghWintab);
		ghWintab = NULL;
	}

	// NULL out pointers
	gpWTInfoA = NULL;
	gpWTInfoW = NULL;
	gpWTClose = NULL;
	gpWTOpenA = NULL;
	gpWTOpenW = NULL;
	gpWTPacket = NULL;
	gpWTEnable = NULL;
	gpWTOverlap = NULL;
	gpWTSave = NULL;
	gpWTConfig = NULL;
	gpWTGetA = NULL;
	gpWTGetW = NULL;
	gpWTSetA = NULL;
	gpWTSetW = NULL;
	gpWTRestore = NULL;
	gpWTExtSet = NULL;
	gpWTExtGet = NULL;
	gpWTQueueSizeSet = NULL;
	gpWTDataPeek = NULL;
	gpWTPacketsGet = NULL;
	gpWTMgrOpen = NULL;
	gpWTMgrClose = NULL;
	gpWTMgrDefContext = NULL;
	gpWTMgrDefContextEx = NULL;
}
