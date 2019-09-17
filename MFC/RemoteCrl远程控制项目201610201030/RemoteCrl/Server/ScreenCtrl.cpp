// ScreenCtrl.cpp: implementation of the ScreenCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ScreenCtrl.h"
#include "command.h"
#include "peersocket.h"
#include "capturescreen.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
bool PeerScreenMouseKey(SOCKET s)
{
	DWORD retLen;
	KEYMOUSE keymouse;
while(1)
{
	//////////取得鼠标键盘值///////////
	if(!PeerRecvDataS(s,(char*)&keymouse,sizeof(keymouse),&retLen))
	{
		return false;
	}
	switch(keymouse.style)
	{
		case PEER_MOUSE_LEFTDOWN:
			mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_LEFTDOWN,keymouse.x,keymouse.y,0,0);
			break;
		case PEER_MOUSE_LEFTUP:
			mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_LEFTUP,keymouse.x,keymouse.y,0,0);
			break;
		case PEER_MOUSE_RIGHTDOWN:
			mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_RIGHTDOWN,keymouse.x,keymouse.y,0,0);
			break;
		case PEER_MOUSE_RIGHTUP:
			mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_RIGHTUP,keymouse.x,keymouse.y,0,0);
			break;
		case PEER_MOUSE_MIDDLEDOWN:
			mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MIDDLEDOWN,keymouse.x,keymouse.y,0,0);
			break;
		case PEER_MOUSE_MIDDLEUP:
			mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MIDDLEUP,keymouse.x,keymouse.y,0,0);
			break;
		case PEER_MOUSE_LDBCLICK:
			mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_LEFTDOWN,keymouse.x,keymouse.y,0,0);
			mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_LEFTUP,keymouse.x,keymouse.y,0,0);
			mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_LEFTDOWN,keymouse.x,keymouse.y,0,0);
			mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_LEFTUP,keymouse.x,keymouse.y,0,0);
			break;
		case PEER_MOUSE_RDBCLICK:
			mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_RIGHTDOWN,keymouse.x,keymouse.y,0,0);
			mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_RIGHTUP,keymouse.x,keymouse.y,0,0);
			mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_RIGHTDOWN,keymouse.x,keymouse.y,0,0);
			mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_RIGHTUP,keymouse.x,keymouse.y,0,0);
			break;
		case PEER_MOUSE_MDBCLICK:
			mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MIDDLEDOWN,keymouse.x,keymouse.y,0,0);
			mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MIDDLEUP,keymouse.x,keymouse.y,0,0);
			mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MIDDLEDOWN,keymouse.x,keymouse.y,0,0);
			mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MIDDLEUP,keymouse.x,keymouse.y,0,0);
			break;
		case PEER_MOUSE_MOVE:
			mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE,keymouse.x,keymouse.y,0,0);
			break;
		case PEER_KEY_DOWN:
			keybd_event(keymouse.nkey,0,KEYEVENTF_EXTENDEDKEY,0);
			break;
		case PEER_KEY_UP:
			keybd_event(keymouse.nkey,0,KEYEVENTF_EXTENDEDKEY|KEYEVENTF_KEYUP,0);
			break;
		default:
			break;
	}
}
	return true;
}
/////////////////截取屏幕/////////////////
bool PeerScreenGet(SOCKET s)
{
	DWORD retLen;
	SCREEN screen;
	//////////屏幕///////////
	while(1)
	{
		if(!PeerRecvDataS(s,(char*)&screen,sizeof(screen),&retLen))
		{
			return false;
		}
		if(screen.BmpSize==10000) ///客户端已经退出
			break;
		EnterCriticalSection(&csCaptureScreen);
		if(!GetScreenData(24))
		{
			LeaveCriticalSection(&csCaptureScreen);
			return false;
		}
		screen.BmpSize=dwBmpSize;
		screen.BmpInfoSize=dwBmpInfoSize;
		screen.BmpCX=iBmpCX;
		screen.BmpCY=iBmpCY;
		if(!PeerSendDataS(s,(char*)&screen,sizeof(screen),&retLen))
		{
			LeaveCriticalSection(&csCaptureScreen);
			return false;
		}
		if(!PeerSendDataS(s,(char*)lpBmpData,dwBmpSize,&retLen))
		{
			LeaveCriticalSection(&csCaptureScreen);
			return false;
		}
		LeaveCriticalSection(&csCaptureScreen);
	}
	return true;
}
