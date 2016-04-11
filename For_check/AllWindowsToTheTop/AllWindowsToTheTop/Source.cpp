#include <tchar.h>
#include <Windows.h>

#pragma comment(linker, "\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' \
publicKeyToken='6595b64144ccf1df' language='*'\"")

BOOL CALLBACK EnumWindowsProc(HWND hWindow, LPARAM lParam);
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

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

	if (RegisterClassEx(&wc))
	{
		HWND hWindow = CreateWindowEx(0, szClassWindow, TEXT("Everybody to the top"),
			WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL,
			NULL, hInstance, NULL);

		ShowWindow(hWindow, nCmdShow);
		UpdateWindow(hWindow);

		MessageBox(NULL, TEXT("Press CTRL to put everything to the top"),
			TEXT("Top program"), MB_OK | MB_ICONINFORMATION);

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

BOOL CALLBACK EnumWindowsProc(HWND hWindow, LPARAM lParam)
{
	// Дескриптор окна приложения.
	HWND hApplication = (HWND)lParam;

	CONST INT nSize = 255;

	TCHAR szCaption[nSize] = {};
	TCHAR szClassName[nSize] = {};
	TCHAR szMessage[nSize] = {};

	// Получение текста заголовка текущего окна верхнего уровня.
	GetWindowText(hWindow, szCaption, nSize);

	// Получение имени класса текущего окна верхнего уровня.
	GetClassName(hWindow, szClassName, nSize);
	if (IsWindowVisible(hWindow))
	{
		RECT a; //we need RECT example to write X and Y coordinates
		LPRECT lpRect = &a; // pointer for X and Y coordinates
		GetWindowRect(hWindow, lpRect); // we find coordinates of our window

		if ((lpRect->bottom - lpRect->top >= 50) && (lpRect->right - lpRect->left >= 50))
			MoveWindow(hWindow, 0, 0, 200, 200, NULL);
	}
	return true;
}

LRESULT CALLBACK WindowProcedure(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;

	switch (nMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_CONTROL)
		{
			EnumWindows(
				EnumWindowsProc, // Указатель на функцию обратного вызова.
				(LPARAM)hWindow); // Аргумент, передаваемый в функцию обратного вызова.
		}
		break;
	default:
		result = DefWindowProc(hWindow, nMessage, wParam, lParam);
		break;
	}

	return result;
}