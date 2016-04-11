#include <windows.h>
#include <tchar.h>
#include <time.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Игра");
LPWSTR question[80];
UINT sec = 0;
UINT count = 0;
UINT max = 0;

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
	hWnd = CreateWindowEx(0, szClassWindow, TEXT("Нажмите Enter для начала игры"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 500, 150, NULL, NULL, hInst, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}
	return lpMsg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_TIMER:
	{
		if (sec > 0)
		{
			sec--;
			wsprintf((LPWSTR)question, L"Seconds left: %d", sec);
			SetWindowText(hWnd, (LPWSTR)question);
		}
		else
		{
			KillTimer(hWnd, 1);
			if (count > max)
			{
				max = count;
				wsprintf((LPWSTR)question, L"Congrats! New record! You pushed button %d times", count);
				MessageBox(0, (LPWSTR)question, L"ClickGame", MB_OK | MB_ICONINFORMATION);
				SetWindowText(hWnd, L"Push Enter to start new game or Esc to Quit!");
			}
			else
			{
				wsprintf((LPWSTR)question, L"Our record is %d! You pushed button %d times", max, count);
				MessageBox(0, (LPWSTR)question, L"ClickGame", MB_OK | MB_ICONINFORMATION);
				SetWindowText(hWnd, L"Push Enter to start new game or Esc to Quit!");
			}
		}
		break;
	}
	case WM_KEYDOWN:
		if (wParam == VK_RETURN)
		{
			if (sec == 0) //You can push enter only if timer does not work
			{
				SetTimer(hWnd, 1, 1000, NULL);
				sec = 20;
				count = 0;
			}
		}
		else if (wParam == VK_ESCAPE)
		{
			KillTimer(hWnd, 1);
			PostQuitMessage(0);
		}
		break;
	case WM_LBUTTONDOWN:
		if (sec != 0) //Clicks are couned only if timer is active
			count++;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}