
// chatDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CchatDlg ��ȭ ����
class CchatDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CchatDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CIPAddressCtrl m_IPAddress;
	CListBox m_listChat;
	int m_nChatMode;
	CString m_strMyIP;
	CString m_strOtherIP;
	afx_msg void OnClickedRadioServer();
	afx_msg void OnRadioClient();
	afx_msg void OnClickedButtonConnect();
	afx_msg void OnClickedButtonSend();
	void ReceiveData(CString strReceive);
	void Accept(CString strSock);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEditSend();
//	CString ID;
	afx_msg void OnEnChangeEditId();
//	CString m_strMyID;
//	CString m_strOtherID;
	CEdit m_IdBox;
//	CString m_strMyID;
//	CString m_strOtherID;
	afx_msg void OnLbnSelchangeListChat();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonClear2();
	afx_msg void OnBnClickedButtonSmile();
	afx_msg void OnBnClickedButtonSmile8();
	afx_msg void OnBnClickedButtonSmile7();
	afx_msg void OnBnClickedButtonSmile6();
	afx_msg void OnBnClickedButtonSmile5();
	afx_msg void OnBnClickedButtonSmile4();
	afx_msg void OnBnClickedButtonSmile3();
	afx_msg void OnBnClickedButtonSmile2();
};
