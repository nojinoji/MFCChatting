
// chatDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "chat.h"
#include "chatDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CchatDlg ��ȭ ����



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


// CchatDlg �޽��� ó����

BOOL CchatDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	char name[255];
//	PHOSTENT hostinfo;
	if (gethostname(name, sizeof(name)) == 0)
		// if ((hostinfo = gethostbyname(name)) != NULL)
			//m_strMyIP = inet_ntoa(*(struct in_addr *)*hostinfo->h_addr_list);
	
	m_IPAddress.SetWindowTextW(m_strMyIP);
	m_IPAddress.EnableWindow(FALSE);
	SetDlgItemText(IDC_BUTTON_CONNECT, _T("Open"));

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CchatDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CchatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CchatDlg::OnClickedRadioServer() //���� ��ư ���� ����
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_IPAddress.SetWindowText(m_strMyIP);
	m_IPAddress.EnableWindow(FALSE);
	SetDlgItemText(IDC_BUTTON_CONNECT, _T("OPEN"));
}


void CchatDlg::OnRadioClient() //���� ��ư Ŭ���̾�Ʈ ����
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_IPAddress.SetWindowText(_T(""));
	m_IPAddress.EnableWindow(TRUE);
	SetDlgItemText(IDC_BUTTON_CONNECT, _T("CONNECT"));
}


void CchatDlg::OnClickedButtonConnect() //IP�� �Է��ؼ� ó���ϴ� ��
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
			int sel = m_listChat.InsertString(-1, _T("����Ǿ����ϴ�."));
			m_listChat.SetCurSel(sel);
		}
		else {
			AfxMessageBox(_T("������ ������ IP�ּҸ��Է��ϼ���"));
		}
	}
}


void CchatDlg::OnClickedButtonSend() //send ��ư�� ������ ��
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strSend, strInsert;
	GetDlgItemText(IDC_EDIT_SEND, strSend);
	if (strSend != "������") {
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CchatDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CchatDlg::OnEnChangeEditSend()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CchatDlg::OnEnChangeEditId()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CchatDlg::OnLbnSelchangeListChat()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


BOOL CchatDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_listChat.ResetContent();
}


void CchatDlg::OnBnClickedButtonSmile()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetDlgItemText(IDC_EDIT_SEND, _T("^^"));
}


void CchatDlg::OnBnClickedButtonSmile8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetDlgItemText(IDC_EDIT_SEND, _T("-_-;"));
}


void CchatDlg::OnBnClickedButtonSmile7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetDlgItemText(IDC_EDIT_SEND, _T("=_= "));
}


void CchatDlg::OnBnClickedButtonSmile6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetDlgItemText(IDC_EDIT_SEND, _T("(^ 3^)"));
}


void CchatDlg::OnBnClickedButtonSmile5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetDlgItemText(IDC_EDIT_SEND, _T("o(^-^)o"));
}


void CchatDlg::OnBnClickedButtonSmile4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetDlgItemText(IDC_EDIT_SEND, _T("(��_��) "));
}


void CchatDlg::OnBnClickedButtonSmile3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetDlgItemText(IDC_EDIT_SEND, _T("(ToT) "));
}


void CchatDlg::OnBnClickedButtonSmile2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetDlgItemText(IDC_EDIT_SEND, _T("(^-^)v "));
}
