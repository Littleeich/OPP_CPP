#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

VOID AddKeyboardMessageInfo(TCHAR chKey, WORD wRepeat);
VOID AddKeyboardKeyMessageInfo(LPCTSTR pcszMessage, UINT nKeyCode, WORD wRepeat);
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

TCHAR title[80];
int pos = 6;

INT WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR szCmdLine, INT nCmdShow)
{
	TCHAR szClassWindow[] = TEXT("Win32Application");

	WNDCLASSEX wc = {};
	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(wc);
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = szClassWindow;
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	INT nExitCode = 0;
	
	wsprintf(/*(LPWSTR)*/title, TEXT("Title1"));

	if (RegisterClassEx(&wc))
	{
		HWND hWindow = CreateWindowEx(0, szClassWindow, /*(LPWSTR)*/ title,
			WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL,
			NULL, hInstance, NULL);

		ShowWindow(hWindow, nCmdShow);
		UpdateWindow(hWindow);

		MSG message = {};

		while (GetMessage(&message, NULL, 0, 0))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		nExitCode = message.wParam;
	}

	return nExitCode;
}

VOID AddKeyboardMessageInfo(TCHAR chKey)
{

	char t = (char)chKey;

	if (t == 8)
	{
		if (pos == 0)
			return;
		else
		{
			title[pos - 1] = '\0';
			pos--;
		}
	}
	else
	{
		title[pos] = t;
		title[pos + 1] = '\0';
		pos++;
	}

}

LRESULT CALLBACK WindowProcedure(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;

	switch (nMessage)
	{
	case WM_CHAR:
		AddKeyboardMessageInfo(wParam);
		SetWindowText(hWindow, (LPWSTR)title);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		result = DefWindowProc(hWindow, nMessage, wParam, lParam);
		break;
	}

	return result;
}