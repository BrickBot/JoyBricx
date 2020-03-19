// JoyBricxDlg.h : ヘッダー ファイル
//

#if !defined(AFX_JOYBRICXDLG_H__B9C9FBCA_39D5_4D8D_ACED_4B6A2FAFD310__INCLUDED_)
#define AFX_JOYBRICXDLG_H__B9C9FBCA_39D5_4D8D_ACED_4B6A2FAFD310__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <time.h>
#include <sys/timeb.h>
#define MAXREC 1000
/////////////////////////////////////////////////////////////////////////////
// CJoyBricxDlg ダイアログ

class CJoyBricxDlg : public CDialog
{
// 構築
public:
	struct _timeb m_start;
	HANDLE m_hCom;
	CJoyBricxDlg(CWnd* pParent = NULL);	// 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CJoyBricxDlg)
	enum { IDD = IDD_JOYBRICX_DIALOG };
	CSliderCtrl	m_sense;
	CButton	m_Rcx;
	CButton	m_Spy;
	CButton	m_Stop;
	CButton	m_Start;
	CButton	m_nqc;
	CButton	m_save;
	CButton	m_replay;
	CButton	m_CH3;
	CButton	m_CH2;
	CButton	m_CH1;
	CStatic	m_pict;
	//}}AFX_DATA

	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CJoyBricxDlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	HICON m_hIcon;

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CJoyBricxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	virtual void OnCancel();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnCh1();
	afx_msg void OnCh2();
	afx_msg void OnCh3();
	afx_msg void OnStart();
	afx_msg void OnStop();
	afx_msg void OnRep();
	afx_msg void OnSave();
	afx_msg void OnLoad();
	afx_msg void OnAbout();
	afx_msg void OnSpy();
	afx_msg void OnRcx();
	afx_msg void OnReleasedcaptureSense(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	unsigned long int m_joyhome;
	bool m_spymode;
	void rcxsend();
	void spysend();
	void SaveCheck();
	CString m_suf;
	CString m_ofile;
	CString m_subname;
	CString m_fname;
	bool m_replaying;
	bool m_relaying;
	int m_repcnt;
	void replay();
	int m_recnum;
	_int32 m_act[MAXREC];
	bool m_saved;
	void record();
	FILE *m_ftower;
	bool m_record;
	int m_stopcnt;
	DWORD PrevWrite;
	DWORD PrevRead;
	DWORD PrevReadfirst;
	WORD m_PrevRxspeed;
	WORD m_PrevTxspeed;
	int m_nch;
	int n_ch;
	void disp_stat();
	CBitmap m_bitmap[9];
	void keyboard();
	void joy();
	void mouse(CPoint p);
	UINT m_dir;
	unsigned char m_CurSig[14];
	void drive();
	void send();
	UINT m_ch;
	WORD m_PrevLinkMode;
	bool m_joy;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_JOYBRICXDLG_H__B9C9FBCA_39D5_4D8D_ACED_4B6A2FAFD310__INCLUDED_)
