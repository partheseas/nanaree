fn main() {
    windows::build!(Windows::Win32::{
        Foundation::{HWND, HPARAM, LPARAM, HINSTANCE, HRESULT},
        Graphics::Gdi::HBRUSH,
        UI::WindowsAndMessaging::{CreateWindowExW, CS_HREDRAW, LoadCursor, IDC_ARROW, LoadIconW, SYS_COLOR_INDEX, WNDCLASSEXW, WNDCLASS_STYLES},
    });
}
