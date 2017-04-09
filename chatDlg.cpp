
// chatDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "chat.h"
#include "chatDlg.h"
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


// CchatDlg 대화 상자



CchatDlg::CchatDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHAT_DIALOG, pParent)
	, m_nChatMode(0)
	, m_strMyIP(_T(""))
	, m_strOtherIP(_T(""))

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CchatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IPADDRESS_SERVER, m_IPAddress);
	DDX_Control(pDX, IDC_LIST_CHAT, m_listChat);
	DDX_Radio(pDX, IDC_RADIO_SERVER, m_nChatMode);

}

BEGIN_MESSAGE_MAP(CchatDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO_SERVER, &CchatDlg::OnClickedRadioServer)
	ON_COMMAND(IDC_RADIO_CLIENT, &CchatDlg::OnRadioClient)
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &CchatDlg::OnClickedButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CchatDlg::OnClickedButtonSend)
	ON_EN_CHANGE(IDC_EDIT_SEND, &CchatDlg::OnEnChangeEditSend)
	ON_LBN_SELCHANGE(IDC_LIST_CHAT, &CchatDlg::OnLbnSelchangeListChat)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CchatDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_SMILE, &CchatDlg::OnBnClickedButtonSmile)
	ON_BN_CLICKED(IDC_BUTTON_SMILE8, &CchatDlg::OnBnClickedButtonSmile8)
	ON_BN_CLICKED(IDC_BUTTON_SMILE7, &CchatDlg::OnBnClickedButtonSmile7)
	ON_BN_CLICKED(IDC_BUTTON_SMILE6, &CchatDlg::OnBnClickedButtonSmile6)
	ON_BN_CLICKED(IDC_BUTTON_SMILE5, &CchatDlg::OnBnClickedButtonSmile5)
	ON_BN_CLICKED(IDC_BUTTON_SMILE4, &CchatDlg::OnBnClickedButtonSmile4)
	ON_BN_CLICKED(IDC_BUTTON_SMILE3, &CchatDlg::OnBnClickedButtonSmile3)
	ON_BN_CLICKED(IDC_BUTTON_SMILE2, &CchatDlg::OnBnClickedButtonSmile2)
END_MESSAGE_MAP()


// CchatDlg 메시지 처리기

BOOL CchatDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	char name[255];
//	PHOSTENT hostinfo;
	if (gethostname(name, sizeof(name)) == 0)
		// if ((hostinfo = gethostbyname(name)) != NULL)
			//m_strMyIP = inet_ntoa(*(struct in_addr *)*hostinfo->h_addr_list);
	
	m_IPAddress.SetWindowTextW(m_strMyIP);
	m_IPAddress.EnableWindow(FALSE);
	SetDlgItemText(IDC_BUTTON_CONNECT, _T("Open"));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CchatDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CchatDlg::OnPaint()
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
HCURSOR CchatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CchatDlg::OnClickedRadioServer() //라디오 버튼 서버 선택
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_IPAddress.SetWindowText(m_strMyIP);
	m_IPAddress.EnableWindow(FALSE);
	SetDlgItemText(IDC_BUTTON_CONNECT, _T("OPEN"));
}


void CchatDlg::OnRadioClient() //라디오 버튼 클라이언트 선택
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_IPAddress.SetWindowText(_T(""));
	m_IPAddress.EnableWindow(TRUE);
	SetDlgItemText(IDC_BUTTON_CONNECT, _T("CONNECT"));
}


void CchatDlg::OnClickedButtonConnect() //IP를 입력해서 처리하는 곳
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	if (!m_nChatMode) { //server
		((CchatApp*)AfxGetApp())->InitServer();
		GetDlgItem(IDC_RADIO_SERVER)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO_CLIENT)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_CONNECT)->EnableWindow(FALSE);
		int sel = m_listChat.InsertString(-1, _T("Server Open"));
		m_listChat.SetCurSel(sel);

	}
	else { //client
		CString strIP, strID;
		GetDlgItemText(IDC_IPADDRESS_SERVER, strIP);
		if (strIP != _T("0.0.0.0")) {
			GetDlgItem(IDC_RADIO_SERVER)->EnableWindow(FALSE);
			GetDlgItem(IDC_RADIO_CLIENT)->EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON_CONNECT)->EnableWindow(FALSE);
			((CchatApp*)AfxGetApp())->Connect(strIP);
			m_strOtherIP = strIP;
			int sel = m_listChat.InsertString(-1, _T("연결되었습니다."));
			m_listChat.SetCurSel(sel);
		}
		else {
			AfxMessageBox(_T("접속할 서버의 IP주소를입력하세요"));
		}
	}
}


void CchatDlg::OnClickedButtonSend() //send 버튼을 눌렀을 때
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strSend, strInsert;
	GetDlgItemText(IDC_EDIT_SEND, strSend);
	if (strSend != "금지어") {
		strInsert.Format(_T("[%s]:%s"), _T("MY"), strSend);
		theApp.SendData(strSend);
		int sel = m_listChat.InsertString(-1, strInsert);
		m_listChat.SetCurSel(sel);
	}
	else {
		((CchatApp*)AfxGetApp())->CloseChild();
	}
	
	SetDlgItemText(IDC_EDIT_SEND, _T(""));
}


void CchatDlg::ReceiveData(CString strReceive)
{
	CString strInsert;
	strInsert.Format(_T("[%s]:%s"), _T("Other"), strReceive);
	int sel = m_listChat.InsertString(-1, strInsert);
	m_listChat.SetCurSel(sel);
}


void CchatDlg::Accept(CString strSock)
{
	m_strOtherIP = strSock;
}


void CchatDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CchatDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CchatDlg::OnEnChangeEditSend()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CchatDlg::OnEnChangeEditId()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CchatDlg::OnLbnSelchangeListChat()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


BOOL CchatDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->message == WM_KEYDOWN || pMsg->message == WM_KEYUP)
	{
		if (pMsg->wParam == VK_RETURN)
		{
			if (pMsg->message == WM_KEYUP) {
				OnClickedButtonSend();
			}
			return FALSE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CchatDlg::OnBnClickedButtonClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_listChat.ResetContent();
}


void CchatDlg::OnBnClickedButtonSmile()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetDlgItemText(IDC_EDIT_SEND, _T("^^"));
}


void CchatDlg::OnBnClickedButtonSmile8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetDlgItemText(IDC_EDIT_SEND, _T("-_-;"));
}


void CchatDlg::OnBnClickedButtonSmile7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetDlgItemText(IDC_EDIT_SEND, _T("=_= "));
}


void CchatDlg::OnBnClickedButtonSmile6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetDlgItemText(IDC_EDIT_SEND, _T("(^ 3^)"));
}


void CchatDlg::OnBnClickedButtonSmile5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetDlgItemText(IDC_EDIT_SEND, _T("o(^-^)o"));
}


void CchatDlg::OnBnClickedButtonSmile4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetDlgItemText(IDC_EDIT_SEND, _T("(づ_ど) "));
}


void CchatDlg::OnBnClickedButtonSmile3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetDlgItemText(IDC_EDIT_SEND, _T("(ToT) "));
}


void CchatDlg::OnBnClickedButtonSmile2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetDlgItemText(IDC_EDIT_SEND, _T("(^-^)v "));
}
