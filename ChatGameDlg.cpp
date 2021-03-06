
// ChatGameDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ChatGame.h"
#include "ChatGameDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CChatGameDlg 대화 상자

/*
char *g_arrStaticCaption[STATICMAX_CONTROL_TMAX] = {
	"java","c++","unity","jsp","directx"
};
*/

char *g_arrStaticCaption[STATICMAX_CONTROL_TMAX] = {
	"aa","bb","cc","dd","ee"
};


CChatGameDlg::CChatGameDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHATGAME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatGameDlg::DoDataExchange(CDataExchange* pDX)
{

	CDialogEx::DoDataExchange(pDX);

	for (int i = 0; i < STATICMAX_CONTROL_TMAX; i++)
	{
		DDX_Control(pDX, IDC_STATIC_1 + i, m_StaticCtrl[i]);
		DDX_Text(pDX, IDC_STATIC_1 + i, m_strStatic[i]);
		



	}

	DDX_Text(pDX, IDC_EDIT_CHAT, m_strEditChat);
	

}

BEGIN_MESSAGE_MAP(CChatGameDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CHECK, &CChatGameDlg::OnBnClickedBtnCheck)
	ON_WM_TIMER()
	//ON_EN_CHANGE(IDC_EDIT_CHAT, &CChatGameDlg::OnEnChangeEditChat)
END_MESSAGE_MAP()


// CChatGameDlg 메시지 처리기

BOOL CChatGameDlg::OnInitDialog() // 초기화 값
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다. 여기서부터 초기화 해


	for (int i = 0; i < 5; i++)
	{
		m_strStatic[i] = g_arrStaticCaption[i];

	}

	SetTimer(0, 1000, NULL);//timer 여러개 설정 가능 (첫번째 parameter)



	UpdateData(false);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CChatGameDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CChatGameDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CChatGameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChatGameDlg::OnBnClickedBtnCheck()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	RECT pt;


	GetWindowRect(&pt);
	ScreenToClient(&pt);

	pt.bottom;

	TRACE("%d", pt.bottom); //bottom val = 358




	UpdateData(true);
	m_strEditChat;


}


void CChatGameDlg::OnTimer(UINT_PTR nIDEvent) //여러 스위치를 지정할 수 있다.
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.


	for (int i = 0; i < STATICMAX_CONTROL_TMAX; i++)
	{
		RECT pt;

		m_StaticCtrl[i].GetWindowRect(&pt);

		ScreenToClient(&pt);


		if (pt.top > 270)
		{
			pt.top = 0;

		}

		int x = pt.left;
		int y = pt.top + 10;

		m_StaticCtrl[i].SetWindowPos(NULL, x, y, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE | SWP_NOZORDER);

	}



	if (m_strEditChat == m_strStatic[0])
	{
		m_StaticCtrl[0].ShowWindow(SW_HIDE); //why 초기화..?

		m_StaticCheck[0] = 1;

		

	}

	if (m_strEditChat == m_strStatic[1])
	{
		m_StaticCtrl[1].ShowWindow(SW_HIDE); //why 초기화..?

		m_StaticCheck[1] = 1;

	}

	if (m_strEditChat == m_strStatic[2])
	{
		m_StaticCtrl[2].ShowWindow(SW_HIDE); //why 초기화..?

		m_StaticCheck[2] = 1;

	}

	if (m_strEditChat == m_strStatic[3])
	{
		m_StaticCtrl[3].ShowWindow(SW_HIDE); //why 초기화..?

		m_StaticCheck[3] = 1;

	}


	if (m_strEditChat == m_strStatic[4])
	{
		m_StaticCtrl[4].ShowWindow(SW_HIDE); //why 초기화..?

		m_StaticCheck[4] = 1;

	}







	


	
	if ((m_StaticCheck[0] && m_StaticCheck[1] && m_StaticCheck[2] && m_StaticCheck[3] && m_StaticCheck[4]) == 1)// 게임 클리어
	{

		KillTimer(0);

		

	}
	



	CDialogEx::OnTimer(nIDEvent);
}


