#include <windows.h>
#include <tchar.h>
#include <list>
#include <time.h>

using namespace std;

VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);

BOOL CALLBACK EnumWindowsProc(HWND hWindow, LPARAM lParam);

struct data {
	HWND h;
	RECT rect;
	int direct;  // 1- вправо-вниз, 2 - вправо-вверх, 3-влево-вверх, 4- влево-вниз
	HWND bang;
};

void Restore();
void Bang(data &);
list <data> hList;
INT high = 100;
INT width = 100;
RECT rectScr;

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	srand(time(NULL));
	GetWindowRect(GetDesktopWindow(), &rectScr);
	while (1)
	{
		Restore();
		hList.clear();
		TCHAR str[30];

		EnumWindows(EnumWindowsProc, NULL);
		SetTimer(NULL, 1, 100, TimerProc);
		wsprintf(str, TEXT("Amount of wins: %d"), hList.size());

		if (MessageBox(0, TEXT("Reload?"), str, MB_YESNO | MB_ICONWARNING) == IDNO)
		{
			Restore();
			return 1;
		}
	}
}

VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
	RECT rect;
	int step = 3; // шаг
	for (auto it = hList.begin(); it != hList.end(); it++)
	{
		HWND hWindow = it->h;
		int direct = it->direct;

		GetWindowRect(hWindow, &rect);
		if (rect.top <= rectScr.top)
			direct == 2 ? direct = 1 : direct = 4;
		else if (rect.right >= rectScr.right)
			direct == 1 ? direct = 4 : direct = 3;
		else if (rect.bottom >= rectScr.bottom)
			(direct == 1) ? direct = 2 : direct = 3;
		else if (rect.left <= rectScr.left)
			(direct == 4) ? direct = 1 : direct = 2;
		switch (direct)
		{
		case 1:
			MoveWindow(hWindow, rect.left + step, rect.top + step, width, high, 1);
			break;
		case 2:
			MoveWindow(hWindow, rect.left + step, rect.top - step, width, high, 1);
			break;
		case 3:
			MoveWindow(hWindow, rect.left - step, rect.top - step, width, high, 1);
			break;
		case 4:
			MoveWindow(hWindow, rect.left - step, rect.top + step, width, high, 1);
		}

		it->direct = direct;
		Bang(*it);
	}
}

void Bang(data & app)
{
	RECT rect2;
	RECT rect1;
	HWND hWindow1 = app.h;
	GetWindowRect(hWindow1, &rect1);

	POINT Rect[4] = { rect1.left, rect1.top, rect1.right, rect1.top, rect1.right, rect1.bottom, rect1.left, rect1.bottom };

	HRGN Pol = CreatePolygonRgn(Rect, 4, ALTERNATE);

	for (auto it = hList.begin(); it != hList.end(); it++)
	{
		int direct1 = app.direct;
		HWND hWindow2 = it->h;
		if (hWindow1 == hWindow2) continue;
		GetWindowRect(hWindow2, &rect2);
		if (RectInRegion(Pol, &rect2) && hWindow2 != app.bang)
		{
			if (direct1 == 1) direct1 = 3;
			else if (direct1 == 2) direct1 = 4;
			else if (direct1 == 3) direct1 = 1;
			else if (direct1 == 4) direct1 = 2;
			app.direct = direct1;
			app.bang = hWindow2;
		}
		else if (!RectInRegion(Pol, &rect2) && hWindow2 == app.bang)
			app.bang = 0;
	}
	DeleteObject(Pol);

	return;
}

BOOL CALLBACK EnumWindowsProc(HWND hWindow, LPARAM lParam)
{
	TCHAR str[30];

	RECT a; //we need RECT example to write X and Y coordinates
	LPRECT lpRect = &a; // pointer for X and Y coordinates
	GetWindowRect(hWindow, lpRect); // we find coordinates of our window

	if ((lpRect->bottom - lpRect->top >= 50) && (lpRect->right - lpRect->left >= 50))
	{
		if (IsWindowVisible(hWindow))
		{
			data app;
			GetWindowRect(hWindow, &app.rect);
			app.h = hWindow;
			app.direct = rand() % 4 + 1;
			app.bang = 0;

			hList.push_back(app);
			MoveWindow(hWindow, rand() % rectScr.right - width, rand() % rectScr.bottom - high, width, high, 1);
		}
	}
	return 1;
}

void Restore()
{
	for (auto it = hList.begin(); it != hList.end(); it++)
		MoveWindow(it->h, it->rect.left, it->rect.top, it->rect.right - it->rect.left, it->rect.bottom - it->rect.top, 1);
}