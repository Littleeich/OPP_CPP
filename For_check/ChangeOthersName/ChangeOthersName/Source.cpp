// файл windows.h содержит определения, макросы, и структуры 
// которые используются при написании приложений под Windows.
// без этой библиотеки приложение не запустится.
#include <windows.h>

// позволяет использовать функцию time, для генерации случайных чисел.
#include <ctime>

// прототип оконной процедуры, которая занимается обработкой сообщений
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = L"Каркасное приложение";	// имя класса окна

// точка входа в приложение
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	// 1. определение класса окна
	WNDCLASSEX wcl;
	wcl.cbSize = sizeof(wcl);	// размер в байтах структуры WNDCLASSEX
	// перерисовать всё окно, если изменён размер по горизонтали или по вертикали
	wcl.style = CS_HREDRAW | CS_VREDRAW;	// CS (Class Style) - стиль класса окна (CS_DBLCLKS!)
	wcl.lpfnWndProc = WindowProc;	// адрес оконной процедуры, указатель на функцию WindowProc
	wcl.cbClsExtra = 0;		// используется Windows 
	wcl.cbWndExtra = 0; 	// используется Windows 
	wcl.hInstance = hInst;	// дескриптор данного приложения

	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// загрузка стандартной иконки (посмотреть список иконок!)

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

	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);	// загрузка стандартного курсора (посмотреть список курсоров!)
	// HCURSOR hCursor=LoadCursorFromFile(L"C:\\1.ani");
	// wcl.hCursor = hCursor;
	wcl.hbrBackground = CreateSolidBrush(RGB(255, 120, 0));
	wcl.lpszMenuName = NULL;	// приложение не содержит меню
	wcl.lpszClassName = szClassWindow;	// имя класса окна
	wcl.hIconSm = NULL;	// отсутствие маленькой иконки для связи с классом окна

	// 2. регистрация класса окна
	if (!RegisterClassEx(&wcl))
		return 0; // при неудачной регистрации - выход

	// 3. создание окна
	// создается окно и переменной hWnd присваивается дескриптор окна

	HWND hWnd = CreateWindowEx(
		0,		// расширенный стиль окна (WS_EX_ACCEPTFILES, WS_EX_CLIENTEDGE)
		szClassWindow,	//имя класса окна
		L"Первое окно", // заголовок окна
		WS_OVERLAPPEDWINDOW, // стиль окна (WS_HSCROLL | WS_VSCROLL)
		// WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
		// заголовок, рамка, позволяющая менять размеры, системное меню, кнопки развёртывания и свёртывания окна
		50, 50, rand() % 200 + 200, rand() % 200 + 200,
		//CW_USEDEFAULT,    // х-координата левого верхнего угла окна
		//CW_USEDEFAULT,	// y-координата левого верхнего угла окна
		//CW_USEDEFAULT,	// ширина окна
		//CW_USEDEFAULT,	// высота окна
		NULL,			// дескриптор родительского окна (HWND_DESKTOP)
		NULL,			// дескриптор меню окна
		hInst,		// идентификатор приложения, создавшего окно
		NULL);		// указатель на область данных приложения


	// 4. отображение окна
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd); // перерисовка окна

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

	/* // добавление менюшки (по желанию)
	HMENU main_menu = CreateMenu();
	HMENU menu_help = CreatePopupMenu();
	HMENU menu_view = CreatePopupMenu();
	AppendMenu(main_menu, MF_STRING | MF_POPUP, (UINT)menu_view, L"Просмотр");
	AppendMenu(main_menu, MF_STRING | MF_POPUP, (UINT)menu_help, L"Справка");
	AppendMenu(menu_help, MF_STRING, 1001, L"О программе...");
	AppendMenu(menu_view, MF_STRING, 1002, L"Текст");
	AppendMenu(menu_view, MF_STRING, 1003, L"Графика");
	SetMenu(hWnd, main_menu);
	*/

	// 5. запуск цикла обработки сообщений

	MSG lpMsg;
	while (GetMessage(&lpMsg, NULL, 0, 0)) // получение очередного сообщения из очереди сообщений (пока не придёт WM_QUIT)
	{ // выбирать любые сообщения из любых приложений
		TranslateMessage(&lpMsg);	// трансляция сообщения (потребуется для работы с клавиатурой)
		DispatchMessage(&lpMsg);	// диспетчеризация сообщений
	} // отправка сообщения оконной процедуре
	return lpMsg.wParam;
}

// функция вызывается ОС, не программой!
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{

	HWND hw;

		hw = FindWindow(L"CalcFrame", L"Калькулятор");
		
		SetWindowText(hw, L"Счеты");
		PostQuitMessage(0);
	return 0;
}