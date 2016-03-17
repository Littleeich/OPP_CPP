#include <windows.h>

#pragma comment(linker, "\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' \
publicKeyToken='6595b64144ccf1df' language='*'\"")


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	LPWSTR question[80];
	int min = 0;
	int max = 1000;
	int mid;
	UINT count = 1;
	BOOL knowNum = 0;

	while (!knowNum)
	{
		mid = (min + max) / 2;
		wsprintf((LPWSTR)question, L"Ваше число №%d?", mid);
		int res = MessageBox(0, (LPWSTR)question, L"внимание вопрос", MB_YESNO | MB_ICONEXCLAMATION);
		if (res == IDYES)
		{
			wsprintf((LPWSTR)question, L"Вы использовали %d попыток!", count);
			MessageBox(0, (LPWSTR)question, L"поздравляем!", MB_OK | MB_ICONSTOP);
			knowNum++;
		}
		else
		{
			count++;
			int res = MessageBox(0, L"Ваше число меньше числа компьютера?", L"внимание вопрос", MB_YESNO | MB_ICONEXCLAMATION);

			if (res == IDYES)
				max = mid - 1;
			else
				min = mid + 1;
		}
	}
}