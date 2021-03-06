#include <windows.h>
#include <tchar.h>
#include <time.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Timer");
UINT direct = 1;

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
	hWnd = CreateWindowEx(0, szClassWindow, TEXT("������� Enter ��� ������ ��������"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 400, 400, NULL, NULL, hInst, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}
	return lpMsg.wParam;
}

int counter = 0;

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

	UINT width = GetSystemMetrics(SM_CXSCREEN);
	UINT height = GetSystemMetrics(SM_CYSCREEN);

	switch (message)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_TIMER:
		{
			if (direct == 1)
				if ((X + dX) < width - wWidth)
				{
					X += dX;
				}
				else
				{
					X = width - wWidth;
					direct = 2;
				}
				//MoveWindow(hWnd, X, Y, wWidth, wHeight, true);

			else if (direct == 2)
			{
				if ((Y + dY) < height - wHeight)
				{
					Y += dY;
				}
				else
				{
					Y = height - wHeight;
					direct = 3;
				}
				//MoveWindow(hWnd, X, Y, wWidth, wHeight, true);
			}

			else if (direct == 3)
			{
				if ((X - dX) > 0)
				{
					X -= dX;
				}
				else
				{
					X = 0;
					direct = 4;
				}
				//MoveWindow(hWnd, X, Y, wWidth, wHeight, true);
			} 

			else
			{
				if ((Y - dY) > 0)
				{
					Y -= dY;
				}
				else
				{
					Y = 0;
					direct = 1;
				}
				//MoveWindow(hWnd, X, Y, wWidth, wHeight, true);
			}
			MoveWindow(hWnd, X, Y, wWidth, wHeight, true);
			break; 
		}
	case WM_KEYDOWN:
		if (wParam == VK_RETURN)
		{
			SetTimer(hWnd, 1, 1000, NULL);
			SetWindowText(hWnd, L"������� Esc ��� ���������...");
		}
		else if (wParam == VK_ESCAPE)
		{
			KillTimer(hWnd, 1);
			SetWindowText(hWnd, L"������� Enter ��� ������ ��������");
		}
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}