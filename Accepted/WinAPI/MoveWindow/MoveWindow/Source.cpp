#include <windows.h>
#include <tchar.h>
#include <time.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Move");

int width = GetSystemMetrics(SM_CXSCREEN);
int height = GetSystemMetrics(SM_CYSCREEN);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcl;
	wcl.cbSize = sizeof(wcl);
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	wcl.lpfnWndProc = WindowProc;
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;
	wcl.hInstance = hInst;
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcl.lpszMenuName = NULL;
	wcl.lpszClassName = szClassWindow;
	wcl.hIconSm = NULL;
	if (!RegisterClassEx(&wcl))
		return 0;
	hWnd = CreateWindowEx(0, szClassWindow, TEXT("Mover"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInst, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}
	return lpMsg.wParam;
}

//int X = 30;  //start position by X
//int Y = 30;  //start position by Y
//int wWidth = 400;  //Window Width
//int wHeight = 400; //Window Height


LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	RECT a; //we need RECT example to write X and Y coordinates
	LPRECT lpRect = &a; // pointer for X and Y coordinates
	GetWindowRect(hWnd, lpRect); // we find coordinates of our window
	int X = lpRect->left;  //start position by X
	int Y = lpRect->top;  //start position by Y
	int wWidth = 400;  //Window Width
	int wHeight = 400; //Window Height

	int dX = 50;  // length of step by X
	int dY = 50;  // length of step by Y
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_RIGHT)
			{
				if (X + dX >= width - wWidth)
					X = width - wWidth;
				else
					X += dX;
			}
		else if (wParam == VK_LEFT)
		{
			if (X - dX <= 0)
				X = 0;
			else
				X -= dX;
		}
		else if (wParam == VK_UP)
			if (Y - dY <= 0)
				Y = 0;
			else
				Y -= dY;
		else if (wParam == VK_DOWN)
		{
			if (Y + dY >= height - wHeight)
				Y = height - wHeight;
			else
				Y += dY;
		}
		else if (wParam == VK_SPACE)
		{
			wWidth = 400;
			wHeight = 400;
			X = width / 2 - wWidth / 2;  //left top X coordinate if we want to put our window in the center of the screen
			Y = height / 2 - wHeight / 2; //left top Y coordinate if we want to put our window in the center of the screen
		}
		else if (wParam == VK_RETURN) // if user pushed Enter
		{
			X = 0;
			Y = 0;
			wHeight = height;
			wWidth = width;
		}
		else if (wParam == VK_ESCAPE)
		{
			X = 0;
			Y = 0;
		}
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	MoveWindow(hWnd, X, Y, wWidth, wHeight, true);
	return 0;
}