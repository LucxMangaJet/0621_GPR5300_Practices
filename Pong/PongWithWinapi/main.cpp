#include <Windows.h>
#include <ctime>
#include <string>

#define WIN_WIDTH 640
#define WIN_HEIGHT 480
#define clamp(v, minV, maxV) min(max(v,minV),maxV)



LRESULT CALLBACK WndProc(
	HWND hWnd, // handle to window instance
	UINT msg, // message id
	WPARAM wParam, // message information (single information)
	LPARAM lParam // additional informations (multiple informations)
);

int WINAPI WinMain(
	HINSTANCE hInstance, // handle to own application instance
	HINSTANCE hPrevInstance, // deprecated
	LPSTR szCmdLine, // command line
	int iCmdShow // in which state the application should be started (Normal, Minimised, Maximised)
)
{
	// 1. describe window class
	WNDCLASS wc = {};
	wc.hInstance = hInstance; // application handle
	wc.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
	//wc.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_BACKGROUND + 1); // background color with the default os background color
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW); // arrow cursor
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION); // application icon
	wc.lpszClassName = TEXT("Pong");
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;

	wc.lpfnWndProc = WndProc;

	// 2. register window class
	if (!RegisterClass(&wc)) return 10;

	// 3. calculating window size (optional)
	RECT r{ 100, 100, 100 + WIN_WIDTH, 100 + WIN_HEIGHT }; // left-top corner, right-bottom corner
	DWORD style = (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU);
	AdjustWindowRect(&r, style, false); // add border width, etc. to window rect

	// 4. create window instance
	HWND hWnd = CreateWindow(
		wc.lpszClassName, // window class name
		wc.lpszClassName, // window title
		style, // visual window style
		r.left, r.top, // window position (origin left-top corner)
		r.right - r.left, r.bottom - r.top, // window size
		nullptr, // handle to parent window
		nullptr, // handle to menu instance
		hInstance, // application handle
		nullptr // optional parameters
	);

	if (!hWnd) return 15;

	// 5. show window
	ShowWindow(hWnd, iCmdShow);
	SetFocus(hWnd);


	// 6. run window (Main Game Loop)
	MSG msg = {};
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, nullptr, 0, UINT_MAX, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//Force a redraw
			InvalidateRect(hWnd, NULL, TRUE);
			UpdateWindow(hWnd);
			//Wait
			Sleep(5);
		}
	}

	return msg.wParam;
}



LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);

		return 0;

	case WM_KEYUP:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);

		return 0;

	case WM_PAINT:
	{
		// old GDI (Graphic Device Interface) painting
		PAINTSTRUCT ps = {};
		
		BeginPaint(hWnd, &ps);
		
		//paint here

		EndPaint(hWnd, &ps);

		return 0;
	}

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}
