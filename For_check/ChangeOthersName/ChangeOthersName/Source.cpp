// ���� windows.h �������� �����������, �������, � ��������� 
// ������� ������������ ��� ��������� ���������� ��� Windows.
// ��� ���� ���������� ���������� �� ����������.
#include <windows.h>

// ��������� ������������ ������� time, ��� ��������� ��������� �����.
#include <ctime>

// �������� ������� ���������, ������� ���������� ���������� ���������
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = L"��������� ����������";	// ��� ������ ����

// ����� ����� � ����������
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	// 1. ����������� ������ ����
	WNDCLASSEX wcl;
	wcl.cbSize = sizeof(wcl);	// ������ � ������ ��������� WNDCLASSEX
	// ������������ �� ����, ���� ������ ������ �� ����������� ��� �� ���������
	wcl.style = CS_HREDRAW | CS_VREDRAW;	// CS (Class Style) - ����� ������ ���� (CS_DBLCLKS!)
	wcl.lpfnWndProc = WindowProc;	// ����� ������� ���������, ��������� �� ������� WindowProc
	wcl.cbClsExtra = 0;		// ������������ Windows 
	wcl.cbWndExtra = 0; 	// ������������ Windows 
	wcl.hInstance = hInst;	// ���������� ������� ����������

	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// �������� ����������� ������ (���������� ������ ������!)

	//wcl.hIcon = (HICON)LoadImage( // returns a HANDLE so we have to cast to HICON
	//	NULL,             // hInstance must be NULL when loading from a file
	//	L"C:\\1\\floppy.ico",   // the icon file name
	//	IMAGE_ICON,       // specifies that the file is an icon
	//	0,                // width of the image (we'll specify default later on)
	//	0,                // height of the image
	//	LR_LOADFROMFILE |  // we want to load a file (as opposed to a resource)
	//	LR_DEFAULTSIZE |   // default metrics based on the type (IMAGE_ICON, 32x32)
	//	LR_SHARED         // let the system release the handle when it's no longer used
	//	);

	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);	// �������� ������������ ������� (���������� ������ ��������!)
	// HCURSOR hCursor=LoadCursorFromFile(L"C:\\1.ani");
	// wcl.hCursor = hCursor;
	wcl.hbrBackground = CreateSolidBrush(RGB(255, 120, 0));
	wcl.lpszMenuName = NULL;	// ���������� �� �������� ����
	wcl.lpszClassName = szClassWindow;	// ��� ������ ����
	wcl.hIconSm = NULL;	// ���������� ��������� ������ ��� ����� � ������� ����

	// 2. ����������� ������ ����
	if (!RegisterClassEx(&wcl))
		return 0; // ��� ��������� ����������� - �����

	// 3. �������� ����
	// ��������� ���� � ���������� hWnd ������������� ���������� ����

	HWND hWnd = CreateWindowEx(
		0,		// ����������� ����� ���� (WS_EX_ACCEPTFILES, WS_EX_CLIENTEDGE)
		szClassWindow,	//��� ������ ����
		L"������ ����", // ��������� ����
		WS_OVERLAPPEDWINDOW, // ����� ���� (WS_HSCROLL | WS_VSCROLL)
		// WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
		// ���������, �����, ����������� ������ �������, ��������� ����, ������ ������������ � ���������� ����
		50, 50, rand() % 200 + 200, rand() % 200 + 200,
		//CW_USEDEFAULT,    // �-���������� ������ �������� ���� ����
		//CW_USEDEFAULT,	// y-���������� ������ �������� ���� ����
		//CW_USEDEFAULT,	// ������ ����
		//CW_USEDEFAULT,	// ������ ����
		NULL,			// ���������� ������������� ���� (HWND_DESKTOP)
		NULL,			// ���������� ���� ����
		hInst,		// ������������� ����������, ���������� ����
		NULL);		// ��������� �� ������� ������ ����������


	// 4. ����������� ����
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd); // ����������� ����

	/*#define SW_HIDE             0
	#define SW_SHOWNORMAL       1
	#define SW_NORMAL           1
	#define SW_SHOWMINIMIZED    2
	#define SW_SHOWMAXIMIZED    3
	#define SW_MAXIMIZE         3
	#define SW_SHOWNOACTIVATE   4
	#define SW_SHOW             5
	#define SW_MINIMIZE         6
	#define SW_SHOWMINNOACTIVE  7
	#define SW_SHOWNA           8
	#define SW_RESTORE          9
	#define SW_SHOWDEFAULT      10
	#define SW_FORCEMINIMIZE    11
	#define SW_MAX              11*/

	/* // ���������� ������� (�� �������)
	HMENU main_menu = CreateMenu();
	HMENU menu_help = CreatePopupMenu();
	HMENU menu_view = CreatePopupMenu();
	AppendMenu(main_menu, MF_STRING | MF_POPUP, (UINT)menu_view, L"��������");
	AppendMenu(main_menu, MF_STRING | MF_POPUP, (UINT)menu_help, L"�������");
	AppendMenu(menu_help, MF_STRING, 1001, L"� ���������...");
	AppendMenu(menu_view, MF_STRING, 1002, L"�����");
	AppendMenu(menu_view, MF_STRING, 1003, L"�������");
	SetMenu(hWnd, main_menu);
	*/

	// 5. ������ ����� ��������� ���������

	MSG lpMsg;
	while (GetMessage(&lpMsg, NULL, 0, 0)) // ��������� ���������� ��������� �� ������� ��������� (���� �� ����� WM_QUIT)
	{ // �������� ����� ��������� �� ����� ����������
		TranslateMessage(&lpMsg);	// ���������� ��������� (����������� ��� ������ � �����������)
		DispatchMessage(&lpMsg);	// ��������������� ���������
	} // �������� ��������� ������� ���������
	return lpMsg.wParam;
}

// ������� ���������� ��, �� ����������!
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{

	HWND hw;

		hw = FindWindow(L"CalcFrame", L"�����������");
		
		SetWindowText(hw, L"�����");
		PostQuitMessage(0);
	return 0;
}