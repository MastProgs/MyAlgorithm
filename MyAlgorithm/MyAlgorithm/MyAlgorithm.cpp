// MyAlgorithm.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "WindowsApplication.h"
#include "MyAlgorithm.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE /*hPrevInstance*/,
                     _In_ LPWSTR    /*lpCmdLine*/,
                     _In_ int       nCmdShow)
{		
	if (false == WindowsApplication::Inst().Initialize(hInstance, nCmdShow))
	{
		return FALSE;
	}

    return WindowsApplication::Inst().GoMsgLoop();
}
