#include "main.h"

HINSTANCE hInst;
// WCHAR szTitle[MAX_PATH];
// WCHAR szWindowClass[MAX_PATH];
WCHAR szTitle[] = L"Puppy!";
WCHAR szWindowClass[] = L"Puppy";

int APIENTRY wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow) {
	// LoadStringW(hInstance, IDC_APP_TITLE, szTitle, MAX_PATH);
	// LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_PATH);

	// HACCEL hAccelTable = LoadAcceleratorsW(hInstance,
	// MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

	WNDCLASSEXW wcex = {sizeof(WNDCLASSEXW)};
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	// wcex.hIcon = LoadIconW(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));
	wcex.hIcon = LoadIconW(hInstance, L"visualstudio/Nonoree.ico");
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	// wcex.lpszMenuName = MAKEINTRESOURCE(IDC_WINDOWSPROJECT1);
	wcex.lpszClassName = szWindowClass;
	// wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDC_SMALL));
	wcex.hIconSm = LoadIconW(wcex.hInstance, L"visualstudio/small.ico");

	if (RegisterClassExW(&wcex) == 0) return FALSE;

	hInst = hInstance;

	HWND hwnd = CreateWindowW(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		0,
		CW_USEDEFAULT,
		0,
		NULL,
		NULL,
		hInstance,
		NULL);

	if (!hwnd) return FALSE;

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	// Event pump
	MSG msg;
	while (GetMessageW(&msg, NULL, 0, 0)) {
		// if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		// }
	}

	return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_COMMAND:
		int wmId = LOWORD(wParam);

		switch (wmId) {
		case IDM_ABOUT:
			DialogBoxW(hInst, L"About Puppy", hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProcW(hWnd, message, wParam, lParam);
		}
		break;

	case WM_PAINT:
		PAINTSTRUCT ps;
		RECT rect;
		HDC hdc = BeginPaint(hWnd, &ps);

		GetClientRect(hWnd, &rect);
		DrawTextW(hdc, L"Hi puppy!", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProcW(hWnd, message, wParam, lParam);
	}

	return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}

	return FALSE;
}
