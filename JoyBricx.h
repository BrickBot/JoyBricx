// JoyBricx.h : JOYBRICX �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#if !defined(AFX_JOYBRICX_H__2C5E4694_5ECC_4FA6_AFE5_575DF15965AC__INCLUDED_)
#define AFX_JOYBRICX_H__2C5E4694_5ECC_4FA6_AFE5_575DF15965AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ���C�� �V���{��

/////////////////////////////////////////////////////////////////////////////
// CJoyBricxApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� JoyBricx.cpp �t�@�C�����Q�Ƃ��Ă��������B
//

class CJoyBricxApp : public CWinApp
{
public:
	CJoyBricxApp();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CJoyBricxApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void WinHelp(DWORD dwData, UINT nCmd = HELP_CONTEXT);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����

	//{{AFX_MSG(CJoyBricxApp)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_JOYBRICX_H__2C5E4694_5ECC_4FA6_AFE5_575DF15965AC__INCLUDED_)
