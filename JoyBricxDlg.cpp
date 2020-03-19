// JoyBricxDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "JoyBricx.h"
#include "JoyBricxDlg.h"
#include "TowerApi_m.h"
#include "RCIremocon.h"
#include "RCXremocon.h"
#include "joybutton.h"
#include <mmsystem.h>

#define USBIRT "\\\\.\\legotower1"
#define	INTERVAL	40
#pragma comment (lib, "winmm.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// アプリケーションのバージョン情報で使われている CAboutDlg ダイアログ

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
	// ダイアログ データ
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	
	// ClassWizard は仮想関数のオーバーライドを生成します
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV のサポート
	//}}AFX_VIRTUAL
	
	// インプリメンテーション
protected:
	//{{AFX_MSG(CAboutDlg)
	afx_msg void OnUrl();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
ON_BN_CLICKED(IDC_URL, OnUrl)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJoyBricxDlg ダイアログ

CJoyBricxDlg::CJoyBricxDlg(CWnd* pParent /*=NULL*/)
: CDialog(CJoyBricxDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CJoyBricxDlg)
	//}}AFX_DATA_INIT
	// メモ: LoadIcon は Win32 の DestroyIcon のサブシーケンスを要求しません。
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CJoyBricxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CJoyBricxDlg)
	DDX_Control(pDX, IDC_Sense, m_sense);
	DDX_Control(pDX, IDC_Rcx, m_Rcx);
	DDX_Control(pDX, IDC_Spy, m_Spy);
	DDX_Control(pDX, IDC_Stop, m_Stop);
	DDX_Control(pDX, IDC_Start, m_Start);
	DDX_Control(pDX, IDC_SAVE, m_save);
	DDX_Control(pDX, IDC_REP, m_replay);
	DDX_Control(pDX, IDC_CH3, m_CH3);
	DDX_Control(pDX, IDC_CH2, m_CH2);
	DDX_Control(pDX, IDC_CH1, m_CH1);
	DDX_Control(pDX, IDC_PICT, m_pict);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CJoyBricxDlg, CDialog)
//{{AFX_MSG_MAP(CJoyBricxDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_WM_TIMER()
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_BN_CLICKED(IDC_CH1, OnCh1)
ON_BN_CLICKED(IDC_CH2, OnCh2)
ON_BN_CLICKED(IDC_CH3, OnCh3)
ON_BN_CLICKED(IDC_Start, OnStart)
ON_BN_CLICKED(IDC_Stop, OnStop)
ON_BN_CLICKED(IDC_REP, OnRep)
ON_BN_CLICKED(IDC_SAVE, OnSave)
ON_BN_CLICKED(IDC_LOAD, OnLoad)
ON_BN_CLICKED(IDC_About, OnAbout)
ON_BN_CLICKED(IDC_Spy, OnSpy)
ON_BN_CLICKED(IDC_Rcx, OnRcx)
ON_WM_KEYDOWN()
ON_WM_SHOWWINDOW()
ON_WM_KEYUP()
	ON_WM_CTLCOLOR()
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_Sense, OnReleasedcaptureSense)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

#include "TowerInit.inc"

/////////////////////////////////////////////////////////////////////////////
// CJoyBricxDlg メッセージ ハンドラ

BOOL CJoyBricxDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// "バージョン情報..." メニュー項目をシステム メニューへ追加します。
	
	// IDM_ABOUTBOX はコマンド メニューの範囲でなければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// このダイアログ用のアイコンを設定します。フレームワークはアプリケーションのメイン
	// ウィンドウがダイアログでない時は自動的に設定しません。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンを設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンを設定
	
	// TODO: 特別な初期化を行う時はこの場所に追加してください。
	m_joy = false;
	if (::joySetCapture(this->m_hWnd, JOYSTICKID1, 1, 0) == JOYERR_NOERROR) {
		::joyReleaseCapture(JOYSTICKID1);
		m_joy = true;
		joy();
	}
	if((m_hCom = CreateFile(USBIRT,
		GENERIC_READ | GENERIC_WRITE,
		0, NULL,
		OPEN_EXISTING, 0, NULL)) == INVALID_HANDLE_VALUE) {
		AfxMessageBox("Can't open USB Tower");
		exit(0);
	}
	
	if (!TowerInit()) {
		AfxMessageBox("NG:TowerInit");
		exit(1);
	}
	
	LEGOTowerGetIRSpeed(m_hCom, &m_PrevTxspeed, &m_PrevRxspeed);
	LEGOTowerGetLinkMode(m_hCom, &m_PrevLinkMode);
	LEGOTowerGetTimeouts(m_hCom, &PrevReadfirst, &PrevRead, &PrevWrite);
	
	LEGOTowerReset(m_hCom);
	
	LEGOTowerSetIRSpeed(m_hCom, LT_SPEED_BPS_4800, LT_SPEED_BPS_4800);	
	LEGOTowerSetLinkMode(m_hCom, LT_MODE_IRC);	
	LEGOTowerSetTimeouts(m_hCom, PrevReadfirst, PrevRead, 10);
	
	UINT bitmap[] = {IDB_BITMAP0,IDB_BITMAP1,IDB_BITMAP2,IDB_BITMAP3,
		IDB_BITMAP4,IDB_BITMAP5,IDB_BITMAP6,IDB_BITMAP7,IDB_BITMAP8};
	
	for (int i = 0; i < 9; ++i) {	
		m_bitmap[i].LoadBitmap(bitmap[i]);
	}
#define MAXSENSE 10000
#define DEFAULTSENSE (MAXSENSE/5)
	m_sense.SetRange(0,MAXSENSE);
	m_sense.SetPos(MAXSENSE-DEFAULTSENSE);
	m_joyhome = DEFAULTSENSE * DEFAULTSENSE;
	m_ch = 7;
	m_CH1.SetCheck(1);
	m_CH2.SetCheck(1);
	m_CH3.SetCheck(1);
	m_Stop.SetCheck(1);
	m_Spy.SetCheck(1);
	m_replaying = m_record = false;
	m_recnum = 0;
	m_saved = true;
	m_dir = 0;
	m_fname.Empty();
	m_spymode = true;
	SetTimer(1, INTERVAL, NULL);
	
	return TRUE;  // TRUE を返すとコントロールに設定したフォーカスは失われません。
}

void CJoyBricxDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// もしダイアログボックスに最小化ボタンを追加するならば、アイコンを描画する
// コードを以下に記述する必要があります。MFC アプリケーションは document/view
// モデルを使っているので、この処理はフレームワークにより自動的に処理されます。

void CJoyBricxDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画用のデバイス コンテキスト
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// クライアントの矩形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// アイコンを描画します。
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		disp_stat();
		CDialog::OnPaint();
	}
}

// システムは、ユーザーが最小化ウィンドウをドラッグしている間、
// カーソルを表示するためにここを呼び出します。
HCURSOR CJoyBricxDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CJoyBricxDlg::OnTimer(UINT nIDEvent) 
{	
	static UINT oldir, oldch;
	
	if (nIDEvent == 1) {
		if (m_joy == true) {
			joy();
		}
		keyboard();
	}
	if (oldir != m_dir || oldch != m_ch) {
		oldir = m_dir;
		oldch = m_ch;
		disp_stat();
		record();
		send();		
	}
	replay();
	drive();
	
	CDialog::OnTimer(nIDEvent);
}

void CJoyBricxDlg::send()
{
	static oldsendmode = 0;
	
	if (m_spymode) {
		spysend();
	}
	else {
		rcxsend();
	}
	
	drive();
	SetTimer(1, INTERVAL, NULL);
}

void CJoyBricxDlg::drive()
{
	DWORD cnt;
	
	if (m_dir != 0) {
		m_stopcnt = 3;
	}
	else if (m_stopcnt-- <= 0) {
		m_stopcnt = 0;
	}
	
	if (m_nch != 0 && m_stopcnt > 0) {
		WriteFile(m_hCom, m_CurSig, m_nch, &cnt, NULL);
		LEGOTowerFlush(m_hCom, LT_FLUSH_ALL);
	}
}

void CJoyBricxDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
#if 0
	CString ss;
	ss.Format("Mouce (%d, %d)", point.x, point.y);
	AfxMessageBox(ss);
#endif
	
	point.x -= 150;
	point.y -= 140;
	mouse(point);
	CDialog::OnLButtonDown(nFlags, point);
}

void CJoyBricxDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CPoint p;
	p.x = 0;
	p.y = 0;
	mouse(p);	
	CDialog::OnLButtonUp(nFlags, point);
}

void CJoyBricxDlg::mouse(CPoint p)
{
	static UINT olddir = 0;
	UINT dir, ux, uy, rad;
	
	rad = p.x*p.x + p.y*p.y;
	if (rad > 16384) {
		return;
	}
	
	ux = abs(p.x);
	uy = abs(p.y);
	
	if(rad < 2500) {
		dir = 0;
	}
	else if (ux > uy) {
		if ((uy *100 / ux) < 41) {
			dir = (p.x > 0) ? 3 : 7;
		}
		else {
			if (p.x > 0) {
				dir = (p.y > 0) ? 4 : 2;
			}
			else {
				dir = (p.y > 0) ? 6 : 8;
			}
		}
	}
	else if ((ux * 100 / uy) < 41) {
		dir = (p.y > 0) ? 5 : 1;	
	}
	else {
		if (p.y > 0) {
			dir = (p.x > 0) ? 4 : 6;
		}
		else {
			dir = (p.x > 0) ? 2 : 8;
		}
	}
	
	if (olddir != dir) {
		m_dir = olddir = dir;
	}
}

void CJoyBricxDlg::joy()
{	
	JOYINFOEX joy;
	
	static UINT olddir = 0, oldch = 0;
	UINT dir, ch;
	long int x,y;
	static int orecord = 0;
	int record;
	
	joy.dwSize = sizeof joy;
	joy.dwFlags = JOY_RETURNALL;
	dir = 0;
	record = (m_record) ? 1 : -1;
	
	if (joyGetPosEx(JOYSTICKID1, &joy) != JOYERR_NOERROR) {
		KillTimer(1);
		if (AfxMessageBox("Error on JoyStick\nContinue ?",
			MB_YESNO) == IDYES) {
			m_joy = false;
			SetTimer(1, INTERVAL, NULL);
			return;
		}
		else {
			OnCancel();
		}
	}
	
	ch = joy.dwButtons & (J_BUTTON1|J_BUTTON2|J_BUTTON3|J_BUTTON4);
	if (ch != 0 && oldch != ch) {
		m_ch = oldch = (ch & 8) ? 7 : ch;
	}
	if (joy.dwButtons & J_BUTTON5) {
		record = 1;
	}
	if (joy.dwButtons & J_BUTTON6) {
		record = -1;
	}

	if (orecord != record) {
		orecord = record;
		if (record > 0) {
			OnStart();
		}
		else {
			OnStop();
		}
	}

	if (!m_spymode && (joy.dwButtons & J_BUTTON7)) {
		OnSpy();
	}
	if (m_spymode && (joy.dwButtons & J_BUTTON8)) {
		OnRcx();
	}	
	
	x = (((int) joy.dwXpos) - 0x8000) >> 2;
	y = (((int) joy.dwYpos) - 0x8000) >> 2;
	
	unsigned long ux, uy;
	
	ux = abs(x);
	uy = abs(y);
	
	if((unsigned long)(x*x + y*y) < m_joyhome) {
		dir = 0;
	}
	else if (ux > uy) {
		if ((uy *100 / ux) < 41) {
			dir = (x > 0) ? 3 : 7;
		}
		else {
			if (x > 0) {
				dir = (y > 0) ? 4 : 2;
			}
			else {
				dir = (y > 0) ? 6 : 8;
			}
		}
	}
	else if ((ux * 100 / uy) < 41) {
		dir = (y > 0) ? 5 : 1;
	}
	else {
		if (y > 0) {
			dir = (x > 0) ? 4 : 6;
		}
		else {
			dir = (x > 0) ? 2 : 8;
		}
	}
	
	if (olddir != dir) {
		m_dir = olddir = dir;
	}
}

void CJoyBricxDlg::keyboard()
{
	UINT dir, ch;
	static UINT odir = 0, och = 0;
	bool spymode;
	int record;
	static int orecord;
	
	static const int buttons[] = {'0', VK_F1, VK_F2, VK_F3, VK_F4,
		VK_F5, VK_F6, VK_F7, VK_F8,
		VK_UP, VK_RIGHT, VK_DOWN, VK_LEFT,
	};
	
	dir = 0;
	ch = 0;
	spymode = m_spymode;
	record = (m_record) ? 1 : -1;
	
	for (int i = 0; i < 13; ++i) {
		if (GetKeyState(buttons[i]) & 0x80000000) {
			switch (i) {
			case 0: 
				break;
			case 1:
			case 2:
			case 3:
			case 4:
				ch |= (1 << (i - 1));
				break;
			case 5:
				record = 1;
				break;
			case 6:
				record = -1;
				break;
			case 7:
				spymode = true;
				break;
			case 8:
				spymode = false;
				break;
			case 9:
			case 10:
			case 11:
			case 12:
				dir |= (1 << (i - 9));
				break;
			}
		}
	}
	
	if (spymode != m_spymode) {
		if (spymode) {
			OnSpy();
		}
		else {
			OnRcx();
		}
	}
	
	if (och != ch && m_spymode && ch != 0) {
		m_ch = (ch & 8) ? 7 : ch;
		och = ch;
	}

	if (orecord != record) {
		orecord = record;
		if (record > 0) {
			OnStart();
		}
		else {
			OnStop();
		}
	}
	
	static const char keytab[] = {
		0,1,3,2,5,1,4,2,7,8,3,2,6,8,2};
		dir = keytab[dir];		
		if (odir != dir) {
			m_dir = odir = dir;
		}
}		

void CJoyBricxDlg::disp_stat()
{
	CDC *pDC = m_pict.GetDC();
	CDC myDC;
	myDC.CreateCompatibleDC(pDC);
	CBitmap * oldBMP = myDC.SelectObject(&m_bitmap[m_dir]);
	pDC->BitBlt(0,0,256,256,&myDC,0,0,SRCCOPY);	
	myDC.SelectObject(oldBMP);
	
	m_CH1.SetCheck((m_ch & 1) ? 1 : 0);
	m_CH2.SetCheck((m_ch & 2) ? 1 : 0);
	m_CH3.SetCheck((m_ch & 4) ? 1 : 0);
}

void CJoyBricxDlg::OnCh1() 
{
	if (m_CH1.GetCheck()) {
		m_ch |= 1;
	}
	else {
		m_ch &= ~1;
	}
}

void CJoyBricxDlg::OnCh2() 
{
	if (m_CH2.GetCheck()) {
		m_ch |= 2;
	}
	else {
		m_ch &= ~2;
	}	
}

void CJoyBricxDlg::OnCh3() 
{
	if (m_CH3.GetCheck()) {
		m_ch |= 4;
	}
	else {
		m_ch &= ~4;
	}	
}

void CJoyBricxDlg::OnStart() 
{
	if (m_record) {
		return;
	}
	if (!m_saved) {
		SaveCheck();
		OnStop();
		return;
	}
	m_record = true;
	m_Start.SetCheck(1);
	m_Stop.SetCheck(0);
	
	m_replaying = false;
	m_recnum = 0;
	_ftime(&m_start);
	record();
}

void CJoyBricxDlg::OnStop() 
{
	if (m_record) {
		m_record = false;
		record();
	}
	m_Start.SetCheck(0);
	m_Stop.SetCheck(1);	
}

void CJoyBricxDlg::record()
{
	if (!m_record) {
		return;
	}
	
	struct _timeb now;
	_ftime(&now);
	m_saved = false;
	
	if (m_recnum < MAXREC) {
		m_act[m_recnum] = 
			((now.time - m_start.time) * 1000 
			+ now.millitm - m_start.millitm) & 0x00ffffff;
		m_act[m_recnum] |= ((m_ch << 4) | (m_dir & 0xf)) << 24;		
		m_recnum++;
	}
	else {
		m_record = false;
		m_Stop.SetCheck(1);
	}
}

void CJoyBricxDlg::OnRep() 
{
	if (!m_replaying) {
		m_replay.SetWindowText("Stop");
		_ftime(&m_start);
		m_replaying = true;		
	}
	else {
		m_replaying = false;
		m_replay.SetWindowText("Replay");
	}
	m_repcnt = 0;
}

void CJoyBricxDlg::replay()
{
	UINT ch;
	
	if (!m_replaying) {
		return;
	}
	struct _timeb now;
	
	if (m_repcnt >= m_recnum) {
		send();
		m_replaying = false;
		m_replay.SetWindowText("Replay");
		return;
	}
	
	_ftime(&now);
	if ((m_act[m_repcnt] & 0x00ffffff) >
		((now.time - m_start.time) * 1000 
		+ now.millitm - m_start.millitm)) {
		return;
	}
	ch = (m_act[m_repcnt] >> 28) & 0x0f;
	m_dir = (m_act[m_repcnt++] >> 24) & 0x0f;
	
	if (ch != m_ch) {
		if (m_spymode && (ch & 0x8)) {
			OnRcx();
		}
		else if (!m_spymode && !(ch & 0x8)) {
			OnSpy();
		}
		m_ch = ch;
	}
	send();
}

void CJoyBricxDlg::OnSave() 
{
	CFileDialog outfileDLG(FALSE, "jbx", "*.jbx",
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		"jbx (*.jbx)|*.jbx| nqc (*.nqc)|*.nqc|ALL (*.*)|*.*||");
	
	outfileDLG.m_ofn.lpstrInitialDir= m_fname;
	if (outfileDLG.DoModal() != IDOK) {
		return;
	}
	m_ofile = outfileDLG.GetPathName();
	m_suf = outfileDLG.GetFileExt();
	m_suf.MakeLower();
	
	SetWindowText("JoyBricx - " + m_ofile);
	
	CFile fout;
	if (!fout.Open(m_ofile, CFile::modeWrite|CFile::modeCreate)) {
		AfxMessageBox("Can't open " + m_ofile);
		return;
	}
	if (m_suf == "jbx") {
		fout.Write(&m_act, sizeof(_int32) * m_recnum);
	}
	else if (m_suf == "nqc") {
		const char *NQCtab[] = {
			"Off(OUT_A+OUT_B); Wait(%d)",
				"OnFwd(OUT_A+OUT_B); Wait(%d)",
				"OnFwd(OUT_A); Off(OUT_B); Wait(%d)",
				"OnFwd(OUT_A); OnRev(OUT_B); Wait(%d)",
				"OnRev(OUT_B); Off(OUT_A); Wait(%d)",
				"OnRev(OUT_A+OUT_B); Wait(%d)",
				"OnRev(OUT_A); Off(OUT_B); Wait(%d)",
				"OnFwd(OUT_B); OnRev(OUT_A); Wait(%d)",
				"OnFwd(OUT_B); Off(OUT_A); Wait(%d)",
		};
		
		CString ss;
		UINT dir, olddir, ch;
		_int32 nowt, oldt;
		nowt = oldt = dir = olddir = 0;
		ch = (m_spymode) ? 1 : 8;
		
		ss = "task main()\r\n{\r\n";
		fout.Write((LPCSTR) ss, ss.GetLength());
		for (int i = 0; i < m_recnum; i++) {
			if ((m_act[i] >> 28) & ch) {
				nowt = m_act[i] & 0x00ffffff;
				dir = (m_act[i] >> 24) & 0xf;
			}
			if (nowt != oldt) {
				if (dir != olddir) {
					ss.Format(NQCtab[dir], (nowt - oldt)/10);
					olddir = dir;
					oldt = nowt;
					ss = "\t" + ss + ";\r\n";
					fout.Write((LPCSTR) ss, ss.GetLength());
				}
			}
		}
		ss = "}\r\n";
		fout.Write((LPCSTR) ss, ss.GetLength());		
	}
	fout.Close();
	m_saved = true;
}

void CJoyBricxDlg::OnLoad() 
{
	SaveCheck();
	
	CFileDialog openDLG(TRUE, "jbx", "*.jbx",
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		"jbx (*.jbx)|*.jbx|ALL (*.*)|*.*||");
	openDLG.m_ofn.lpstrInitialDir= m_fname.IsEmpty() ? "c:\\My Documents" : m_fname;
	
	if (openDLG.DoModal() != IDOK) {
		return;
	}
	m_fname = openDLG.GetPathName();
	m_subname = openDLG.GetFileTitle();
	SetWindowText("JoyBricx - " + m_fname);
	
	CFile fin;
	if (!fin.Open(m_fname, CFile::modeRead)) {
		AfxMessageBox("Can't open " + m_fname);
		return;
	}
	int n = fin.Read(&m_act, sizeof(_int32) * MAXREC);
	m_recnum = n / sizeof(_int32);
	m_saved = true;
}

void CJoyBricxDlg::OnAbout() 
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();	
}

void CJoyBricxDlg::SaveCheck()
{
	if (!m_saved) {
		switch (AfxMessageBox("Save changes to file ?", MB_YESNO)) {
		case IDNO:
			break;
		case IDYES:
			OnSave();
			break;
		}
		m_saved = true;
	}	
}

void CAboutDlg::OnUrl() 
{
	ShellExecute(m_hWnd, "open", "http://line.to/mac/MindStorms/JoyBricx/",
		NULL,NULL,SW_SHOW);	
}

void CJoyBricxDlg::spysend()
{
	const UINT RCItable[] = {
		0,(B_RightFwd | B_LeftFwd),
			B_LeftFwd,
			(B_LeftFwd | B_RightRwd), 
			B_LeftRwd,
			(B_RightRwd | B_LeftRwd),
			B_RightRwd,
			(B_LeftRwd | B_RightFwd),
			B_RightFwd,
	};
	
	unsigned char buf[4];
	UINT ch1;
	int i, j;
	static UINT olddir[3] = {0,0,0};
	static stopcnt = 0;
	
	UINT dir[3];
	
	m_nch = 0;
	
	if (m_ch == 7) {
		dir[0] = dir[1] = dir[2] = m_dir;
		UINT button = RCItable[m_dir];
		buf[0] = 4;
		buf[1] = (button >> 8) & 0xf;
		buf[2] = (button >> 4) & 0xf;
		buf[3] = ~(buf[0] + buf[1] + buf[2]) + 1;
		
		m_CurSig[m_nch++] = buf[0] << 4 | (buf[1] & 0xf);
		m_CurSig[m_nch++] = buf[2] << 4 | (buf[3] & 0xf);
	}
	else {
		ch1 = m_ch;
		for (i = 0, j = 1; i < 3; i++, j <<= 1) {
			if (ch1 & j) {
				dir[i] = m_dir;
				UINT button = RCItable[m_dir];
				buf[0] = i + 5;
				buf[1] = (button >> 8) & 0xf;
				buf[2] = (button >> 4) & 0xf;
				buf[3] = ~(buf[0] + buf[1] + buf[2]) + 1;
				
				m_CurSig[m_nch++] = buf[0] << 4 | (buf[1] & 0xf);
				m_CurSig[m_nch++] = buf[2] << 4 | (buf[3] & 0xf);
			}
			else {
				if (olddir[i] != 0) {
					buf[0] = i + 5;
					buf[3] = ~buf[0] + 1;
					m_CurSig[m_nch++] = buf[0] << 4;
					m_CurSig[m_nch++] = buf[3] & 0xf;
					olddir[i] = dir[i];
				}
			}
		}
	}
}

void CJoyBricxDlg::rcxsend()
{
	const UINT RCXtable[] = {
		R_Stop,
			(R_RightFwd | R_LeftFwd),
			R_LeftFwd,
			(R_LeftFwd | R_RightRwd), 
			R_LeftRwd,
			(R_RightRwd | R_LeftRwd),
			R_RightRwd,
			(R_LeftRwd | R_RightFwd),
			R_RightFwd,
	};
	
	static UINT olddir = 0;
	static stopcnt = 0;
	UINT dir;
	
	m_nch = 0;
	
	dir = RCXtable[m_dir];
	
	m_CurSig[m_nch++] = 0x55;
	m_CurSig[m_nch++] = 0xff;
	m_CurSig[m_nch++] = 0x00;
	m_CurSig[m_nch++] = R_Remo;
	m_CurSig[m_nch++] = ~R_Remo;
	
	m_CurSig[m_nch++] = dir & 0xff;
	m_CurSig[m_nch++] = ~m_CurSig[m_nch - 1];
	m_CurSig[m_nch++] = (dir >> 8) & 0xff;
	m_CurSig[m_nch++] = ~m_CurSig[m_nch - 1];
	
	m_CurSig[m_nch++] = m_CurSig[3] + m_CurSig[5] + m_CurSig[7];
	m_CurSig[m_nch++] = ~m_CurSig[m_nch - 1];
	
}

void CJoyBricxDlg::OnSpy() 
{
	LEGOTowerFlush(m_hCom, LT_FLUSH_ALL);
	LEGOTowerReset(m_hCom);
	
	m_Spy.SetCheck(1);
	m_Rcx.SetCheck(0);
	m_spymode = true;
	m_ch &= ~0x08;
	
	LEGOTowerSetIRSpeed(m_hCom, LT_SPEED_BPS_4800, LT_SPEED_BPS_4800);	
	LEGOTowerSetLinkMode(m_hCom, LT_MODE_IRC);	
	LEGOTowerSetTimeouts(m_hCom, PrevReadfirst, PrevRead, 10);	
}

void CJoyBricxDlg::OnRcx() 
{
	LEGOTowerFlush(m_hCom, LT_FLUSH_ALL);
	LEGOTowerReset(m_hCom);
	
	m_Spy.SetCheck(0);
	m_Rcx.SetCheck(1);
	
	m_ch |= 0x08;
	m_spymode = false;
	
	LEGOTowerSetIRSpeed(m_hCom, LT_SPEED_BPS_2400, LT_SPEED_BPS_2400);	
	LEGOTowerSetLinkMode(m_hCom, LT_LINK_IR);	
	LEGOTowerSetTimeouts(m_hCom, PrevReadfirst, PrevRead, 100);	
}

void CJoyBricxDlg::OnCancel() 
{
	static int count;
	
	SaveCheck();
	
	LEGOTowerSetIRSpeed(m_hCom, m_PrevTxspeed, m_PrevRxspeed);
	LEGOTowerSetTimeouts(m_hCom, PrevReadfirst, PrevRead, PrevWrite);
	LEGOTowerSetLinkMode(m_hCom, m_PrevLinkMode);
	CloseHandle(m_hCom);
	CDialog::OnCancel();
}

void CJoyBricxDlg::OnReleasedcaptureSense(NMHDR* pNMHDR, LRESULT* pResult) 
{
	m_joyhome = MAXSENSE - m_sense.GetPos();
	CString ss;
	ss.Format("%d", m_joyhome);
	AfxMessageBox(ss);

	m_joyhome = m_joyhome * m_joyhome;	
	*pResult = 0;
}
