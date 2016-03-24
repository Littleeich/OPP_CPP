#include <ctime>
#include <tchar.h>
#include <Windows.h>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
time_t currentTime = time(NULL);

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
		HWND hWindow = CreateWindowEx(0, szClassWindow, TEXT("Нажмите Enter для результата"),
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

LRESULT CALLBACK WindowProcedure(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;

	switch (nMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
	{
		if (wParam == VK_RETURN)
		{
			LPWSTR dif[80];
			time_t currentTime2 = time(NULL);
			wsprintf((LPWSTR)dif, L"С начала программы прошло %d секунд!", currentTime2 - currentTime);
			SetWindowText(hWindow, (LPWSTR)dif);
		}
	}
	break;
	default:
		result = DefWindowProc(hWindow, nMessage, wParam, lParam);
		break;
	}

	return result;
}