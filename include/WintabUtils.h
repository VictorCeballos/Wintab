#pragma once

#include <windows.h>
#include <stdio.h>
#include <stdarg.h>

#include "msgpack.h"
#include "wintab.h"

// Function pointers to Wintab functions exported from wintab32.dll
using WTINFOA = UINT(API*) (UINT, UINT, LPVOID);
using WTINFOW = UINT(API*) (UINT, UINT, LPVOID);
using WTOPENA = HCTX(API*) (HWND, LPLOGCONTEXTA, BOOL);
using WTOPENW = HCTX(API*) (HWND, LPLOGCONTEXTW, BOOL);
using WTGETA = BOOL(API*) (HCTX, LPLOGCONTEXTA);
using WTGETW = BOOL(API*) (HCTX, LPLOGCONTEXTW);
using WTSETA = BOOL(API*) (HCTX, LPLOGCONTEXTA);
using WTSETW = BOOL(API*) (HCTX, LPLOGCONTEXTW);
using WTCLOSE = BOOL(API*) (HCTX);
using WTENABLE = BOOL(API*) (HCTX, BOOL);
using WTPACKET = BOOL(API*) (HCTX, UINT, LPVOID);
using WTOVERLAP = BOOL(API*) (HCTX, BOOL);
using WTSAVE = BOOL(API*) (HCTX, LPVOID);
using WTCONFIG = BOOL(API*) (HCTX, HWND);
using WTRESTORE = HCTX(API*) (HWND, LPVOID, BOOL);
using WTEXTSET = BOOL(API*) (HCTX, UINT, LPVOID);
using WTEXTGET = BOOL(API*) (HCTX, UINT, LPVOID);
using WTQUEUESIZESET = BOOL(API*) (HCTX, int);
using WTDATAPEEK = int  (API*) (HCTX, UINT, UINT, int, LPVOID, LPINT);
using WTPACKETSGET = int  (API*) (HCTX, int, LPVOID);
using WTMGROPEN = HMGR(API*) (HWND, UINT);
using WTMGRCLOSE = BOOL(API*) (HMGR);
using WTMGRDEFCONTEXT = HCTX(API*) (HMGR, BOOL);
using WTMGRDEFCONTEXTEX = HCTX(API*) (HMGR, UINT, BOOL);

// Loaded Wintab32 API functions
extern HINSTANCE ghWintab;
extern WTINFOA gpWTInfoA;
extern WTINFOW gpWTInfoW;
extern WTOPENA gpWTOpenA;
extern WTOPENW gpWTOpenW;
extern WTGETA gpWTGetA;
extern WTGETW gpWTGetW;
extern WTSETA gpWTSetA;
extern WTSETW gpWTSetW;
extern WTCLOSE gpWTClose;
extern WTPACKET gpWTPacket;
extern WTENABLE gpWTEnable;
extern WTOVERLAP gpWTOverlap;
extern WTSAVE gpWTSave;
extern WTCONFIG gpWTConfig;
extern WTRESTORE gpWTRestore;
extern WTEXTSET gpWTExtSet;
extern WTEXTGET gpWTExtGet;
extern WTQUEUESIZESET gpWTQueueSizeSet;
extern WTDATAPEEK gpWTDataPeek;
extern WTPACKETSGET gpWTPacketsGet;
extern WTMGROPEN gpWTMgrOpen;
extern WTMGRCLOSE gpWTMgrClose;
extern WTMGRDEFCONTEXT gpWTMgrDefContext;
extern WTMGRDEFCONTEXTEX gpWTMgrDefContextEx;

// Helper functions
BOOL LoadWintab(void);
void UnloadWintab(void);
