#pragma once

// CServerSock ��� ����Դϴ�.

class CServerSock : public CAsyncSocket
{
public:
	CServerSock();
	virtual ~CServerSock();
	virtual void OnAccept(int nErrorCode);
};


