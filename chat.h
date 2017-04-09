
// chat.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.
#include "ServerSock.h"
#include "ClientSock.h"
#include "chatDlg.h"


// CchatApp:
// �� Ŭ������ ������ ���ؼ��� chat.cpp�� �����Ͻʽÿ�.
//

class CchatApp : public CWinApp
{
public:
	CchatApp();

// �������Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	CServerSock* m_pServer;
	CClientSock* m_pClient;
	void InitServer();
	void Accept();
	void CleanUp();
	void Connect(CString strIP);
	void SendData(CString strData);
	void ReceiveData();
	void CloseChild();
};

extern CchatApp theApp;