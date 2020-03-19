// JoyBricx.h : JOYBRICX アプリケーションのメイン ヘッダー ファイルです。
//

#if !defined(AFX_JOYBRICX_H__2C5E4694_5ECC_4FA6_AFE5_575DF15965AC__INCLUDED_)
#define AFX_JOYBRICX_H__2C5E4694_5ECC_4FA6_AFE5_575DF15965AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// メイン シンボル

/////////////////////////////////////////////////////////////////////////////
// CJoyBricxApp:
// このクラスの動作の定義に関しては JoyBricx.cpp ファイルを参照してください。
//

class CJoyBricxApp : public CWinApp
{
public:
	CJoyBricxApp();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CJoyBricxApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void WinHelp(DWORD dwData, UINT nCmd = HELP_CONTEXT);
	//}}AFX_VIRTUAL

// インプリメンテーション

	//{{AFX_MSG(CJoyBricxApp)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_JOYBRICX_H__2C5E4694_5ECC_4FA6_AFE5_575DF15965AC__INCLUDED_)
