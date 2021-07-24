mod win {
    windows::include_bindings!();
    pub use Windows::Win32::{Foundation::*, UI::WindowsAndMessaging::*};
}

use win::*;

fn main() {
    let wcex = WNDCLASSEXW {
        cbSize: 1,
        style: CS_HREDRAW | CS_VREDRAW,
        lpfnWndProc: WndProc,
        cbClsExtra: 0,
        cbWndExtra: 0,
        hInstance: 0,
        hIcon: LoadIconW(hInstance, "./resources/main.ico"),
        hCursor: LoadCursor(None, IDC_ARROW),
        hbrBackground: HBRUSH,
        lpszClassName: szWindowClass,
        hIconSm: LoadIconW(hInstance, "./resources/main-small.ico"),
    };

    let hwnd = CreateWindowExW();

    println!("Hello, world!");
}

fn WndProc(hWnd: HWND, message: usize, wParam: WPARAM, lParam: LPARAM) -> LRESULT {}
