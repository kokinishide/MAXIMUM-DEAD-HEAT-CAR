//*********************************************
//
// メイン(main.cpp)
// Author : Junichi Uchiyama
//
//*********************************************

#include <Windows.h>
#include "d3dx9.h"
#include"main.h"
#include "renderer.h"
#include "object2D.h"
#include "object.h"
#include"manager.h"


#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "winmm.lib")

#define CLASS_NAME		("WindowsClass")
#define WINDOW_NAME		("MAXIMUM DEADHEAT CAR")
#define SCREEN_WIDTH	(1280)
#define SCREEN_HEIGHT	(720)
//#define FVF_VERTEX_2D	(D3DFVF_XYZRHW | D3DFVF_DIFFUSE)
#define GAME_FPS		(60)

//struct VERTEX_2D
//{
//	D3DXVECTOR3 pos;
//	float rhw;
//	D3DCOLOR col;
//};

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//HRESULT Init(HWND hWnd, BOOL bWindow);
//void Uninit();
//void Update();
//void Draw();



//グローバル変数
int g_nCountFPS = 0;

CManager* g_pManager = nullptr;


int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hInstancePrev,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	//CManager* pManager = CManager::GetInstance();
	//if (FAILED(pManager->Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)))
	//{
	//	return -1;
	//}
	//pManager->Update();
	//pManager->Draw();
	//pManager->Uninit();
	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),
		CS_CLASSDC,
		WindowProc,
		0,
		0,
		hInstance,
		LoadIcon(NULL, IDI_APPLICATION),
		LoadCursor(NULL, IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 1),
		NULL,
		CLASS_NAME,
		LoadIcon(NULL, IDI_APPLICATION)
	};

	HWND hWnd;
	MSG msg;
	RECT rect = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
	DWORD dwCurrentTime;
	DWORD dwExecLastTime;
	DWORD dwFrameCount;
	DWORD dwFPSLastTime;

	RegisterClassEx(&wcex);

	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

	hWnd = CreateWindowEx(0,
		CLASS_NAME,
		WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		(rect.right - rect.left),
		(rect.bottom - rect.top),
		NULL,
		NULL,
		hInstance,
		NULL);

	/*if (FAILED(Init(hWnd, TRUE)))
	{
		return -1;
	}*/

	timeBeginPeriod(1);
	dwCurrentTime = 0;
	dwExecLastTime = timeGetTime();
	dwFrameCount = 0;
	dwFPSLastTime = timeGetTime();

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	//生成＆初期化
	g_pManager = new CManager();//レンダラー生成
	g_pManager->Init(hInstance, hWnd, TRUE);

	//メッセージループ
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			dwCurrentTime = timeGetTime();

			if ((dwCurrentTime - dwFPSLastTime) >= 500)
			{
				g_nCountFPS = (dwFrameCount * 1000) / (dwCurrentTime - dwFPSLastTime);
				dwFPSLastTime = dwCurrentTime;
				dwFrameCount = 0;
			}
			//マネージャー更新処理
			g_pManager->Update();
			//マネージャー描画処理
			g_pManager->Draw();
			if ((dwCurrentTime - dwExecLastTime) >= (1000 / GAME_FPS))
			{

				dwExecLastTime = dwCurrentTime;

				dwFrameCount++;
			}
		}
	}
	//終了処理
	g_pManager->Uninit();
	delete g_pManager;


	timeEndPeriod(1);

	UnregisterClass(CLASS_NAME, wcex.hInstance);

	return (int)msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	bool result = false;

	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			result = (MessageBox(hWnd, "終了しますか？", "終了メッセージ", MB_YESNO | MB_ICONQUESTION) == IDYES);
			if (result == true)
			{
				DestroyWindow(hWnd);
			}
			break;
		}
		break;
	case WM_CLOSE:
		result = (MessageBox(hWnd, "終了しますか？", "終了メッセージ", MB_YESNO | MB_ICONQUESTION) == IDYES);
		if (result == true)
		{
			DestroyWindow(hWnd);
		}
		else
		{
			return 0;
		}
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

