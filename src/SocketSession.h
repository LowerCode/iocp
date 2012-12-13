#pragma once
#include "sockethandle.h"

class SocketSession :
	public SocketHandle,
	public SocketEventHandle
{
public:
	SocketSession(SocketEventHandle *eventHandle);
	virtual ~SocketSession(void);

	// �����buffer��event����ʱ���ͷţ�����SocketContext��buff��
	BOOL SendBuff(char *buff,DWORD size,int operation,void *cookie = NULL,DWORD timeout = 0);
	BOOL RecvBuff(char *buff,DWORD size,int operation,void *cookie = NULL,DWORD timeout = 0);

	// ����Ҫ�ͷŵ�
	BOOL SendBuff(const char *buff,DWORD size,int operation,void *cookie = NULL,DWORD timeout = 0);
	BOOL RecvBuff(const char *buff,DWORD size,int operation,void *cookie = NULL,DWORD timeout = 0);

	//// ��Э�����������������buffer�ͷ�
	//int SendWSABUF(LPWSABUF lpBuffers,DWORD dwBufferCount,int operation,void *cookie = NULL);
	//int RecvWSABUF(LPWSABUF lpBuffers,DWORD dwBufferCount,int operation,void *cookie = NULL);

	virtual void OnEvent(DWORD ioSize,SocketContext *context,BOOL error);
	virtual void OnTimeout(SocketContext *context){};
	virtual void OnClose(){};

protected:

	BOOL SendContext(LPWSABUF lpBuffers,DWORD dwBufferCount,SocketContext *context);
	BOOL RecvContext(LPWSABUF lpBuffers,DWORD dwBufferCount,SocketContext *context);
};
