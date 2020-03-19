// JoyBricx.cpp : アプリケーション用クラスの定義を行います。
//

#include "stdafx.h"
#include "JoyBricx.h"
#include "JoyBricxDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJoyBricxApp

BEGIN_MESSAGE_MAP(CJoyBricxApp, CWinApp)
	//{{AFX_MSG_MAP(CJoyBricxApp)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJoyBricxApp クラスの構築

CJoyBricxApp::CJoyBricxApp()
{
	// TODO: この位置に構築用のコードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}

/////////////////////////////////////////////////////////////////////////////
// 唯一の CJoyBricxApp オブジェクト

CJoyBricxApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CJoyBricxApp クラスの初期化

BOOL CJoyBricxApp::InitInstance()
{
	AfxEnableControlContainer();

	// 標準的な初期化処理
	// もしこれらの機能を使用せず、実行ファイルのサイズを小さくしたけ
	//  れば以下の特定の初期化ルーチンの中から不必要なものを削除して
	//  ください。

#ifdef _AFXDLL
	Enable3dControls();			// 共有 DLL 内で MFC を使う場合はここをコールしてください。
#else
	Enable3dControlsStatic();	// MFC と静的にリンクする場合はここをコールしてください。
#endif

	CJoyBricxDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: ダイアログが <OK> で消された時のコードを
		//       記述してください。
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: ダイアログが <ｷｬﾝｾﾙ> で消された時のコードを
		//       記述してください。
	}

	// ダイアログが閉じられてからアプリケーションのメッセージ ポンプを開始するよりは、
	// アプリケーションを終了するために FALSE を返してください。
	return FALSE;
}

BOOL CJoyBricxApp::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message == WM_KEYDOWN) {
		return true;
	}
	return CWinApp::PreTranslateMessage(pMsg);
}

void CJoyBricxApp::WinHelp(DWORD dwData, UINT nCmd) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	
//	CWinApp::WinHelp(dwData, nCmd);
}
