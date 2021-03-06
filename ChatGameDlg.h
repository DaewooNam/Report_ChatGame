
// ChatGameDlg.h: 헤더 파일
//

#pragma once
#define STATICMAX_CONTROL_TMAX  5
#include<iostream>



// CChatGameDlg 대화 상자
class CChatGameDlg : public CDialogEx
{
	// 생성입니다.
public:
	CChatGameDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHATGAME_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	CStatic m_StaticCtrl[STATICMAX_CONTROL_TMAX];
	CString m_strStatic[STATICMAX_CONTROL_TMAX];
	CString m_strEditChat;
	CStatic m_strPos;
	BOOL    m_StaticCheck[STATICMAX_CONTROL_TMAX] = {0,};

	
	/*
	for (int i = 0; i < 5; i++)
	{

		CStatic m_Static1;
	}
	CStatic m_Static1;
	CStatic m_Static2;
	CStatic m_Static3;
	CStatic m_Static4;
	*/

public:
	afx_msg void OnBnClickedBtnCheck();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//afx_msg void OnEnChangeEditChat();
};
