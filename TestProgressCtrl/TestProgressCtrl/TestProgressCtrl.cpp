// TestProgressCtrl.cpp : Implementation of WinMain


#include "stdafx.h"
#include "resource.h"
#include "TestProgressCtrl_i.h"
#include "ProgressDlg.h"


class CTestProgressCtrlModule : public CAtlExeModuleT< CTestProgressCtrlModule >
{
public :
	DECLARE_LIBID(LIBID_TestProgressCtrlLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_TESTPROGRESSCTRL, "{B7DFD6C4-12C7-457D-8180-F4E2131F11EE}")
};

CTestProgressCtrlModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, 
                                LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	CProgressDlg dlg;
	dlg.DoModal();
    return _AtlModule.WinMain(nShowCmd);
}

