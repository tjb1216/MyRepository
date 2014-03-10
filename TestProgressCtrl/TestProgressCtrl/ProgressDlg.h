// ProgressDlg.h : Declaration of the CProgressDlg

#pragma once

#include "resource.h"       // main symbols

#include <atlhost.h>

#pragma comment(lib,"comctl32.lib")
#include <commctrl.h>


// CProgressDlg

class CProgressDlg : 
	public CAxDialogImpl<CProgressDlg>
{
public:
	CProgressDlg()
		: m_str1(_T(""))
		, m_str2(_T(""))
	{
	}

	~CProgressDlg()
	{
	}

	enum { IDD = IDD_PROGRESSDLG };

BEGIN_MSG_MAP(CProgressDlg)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	MESSAGE_HANDLER(WM_TIMER, OnTimer)
	COMMAND_HANDLER(IDOK, BN_CLICKED, OnClickedOK)
	COMMAND_HANDLER(IDCANCEL, BN_CLICKED, OnClickedCancel)
	CHAIN_MSG_MAP(CAxDialogImpl<CProgressDlg>)
END_MSG_MAP()

// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		CAxDialogImpl<CProgressDlg>::OnInitDialog(uMsg, wParam, lParam, bHandled);
		bHandled = TRUE;
		InitCommonControls(); //ȷ����ע���˽�������PROGRESS_CLASS
		m_rangehwnd=GetDlgItem(IDC_PROGRESS1);			//�õ��������ľ��
		::SendMessage(m_rangehwnd,PBM_SETRANGE,0,MAKELPARAM(0,100));		//��ʼ���������ķ�Χ
		SetTimer(1011,  2000, NULL);
		return 1;  // Let the system set the focus
	}

	LRESULT OnTimer(UINT /*uMsg*/, WPARAM wParam, LPARAM /*lParam*/, BOOL& bHandled)
	{
		PBRANGE range; //�������ķ�Χ
		SendMessage( m_rangehwnd, PBM_GETRANGE, //��ȡ�������ķ�Χ
			(WPARAM)TRUE, //TRUE ��ʾ����ֵΪ��Χ����Сֵ,FALSE��ʾ�������ֵ
			(LPARAM)&range );
		SendMessage( m_rangehwnd, PBM_DELTAPOS, //���ý���������λ��Ϊ��ǰλ�ü��Ϸ�Χ��1/40
			(WPARAM)((range.iHigh-range.iLow)/10), (LPARAM)0 );
		return 0;
	}

	LRESULT OnClickedOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		EndDialog(wID);
		return 0;
	}

	LRESULT OnClickedCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		EndDialog(wID);
		return 0;
	}

private:
	CString m_str1;
	CString m_str2;
	HWND m_rangehwnd;
	//IProgressBar m_progress;
};


