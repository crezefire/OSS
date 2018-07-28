#include <oss/window.h>

#include <Windows.h>

namespace {
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_DESTROY: PostQuitMessage(0); break;
    default: return DefWindowProc(hWnd, message, wParam, lParam); break;
    }

    return 0;
}

bool RegisterAppClass(HINSTANCE hInstance, char const* const windowName) {
    WNDCLASSEX wcex;

    auto const iconResource = IDI_APPLICATION;

    wcex.cbSize        = sizeof(WNDCLASSEX);
    wcex.style         = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc   = MainWndProc;
    wcex.cbClsExtra    = 0;
    wcex.cbWndExtra    = 0;
    wcex.hInstance     = hInstance;
    wcex.hIcon         = LoadIconA(hInstance, iconResource);
    wcex.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName  = NULL;
    wcex.lpszClassName = windowName;
    wcex.hIconSm       = LoadIconA(wcex.hInstance, iconResource);

    if (!RegisterClassEx(&wcex)) { return false; }

    return true;
}
} // namespace

namespace oss {

std::optional<Window::Handle>
Window::CreateOSWindow(std::string_view name, int const width, int const height) {

    const auto hInstance   = GetModuleHandle(NULL);
    const auto& windowName = name.data();

    if (!RegisterAppClass(hInstance, windowName)) return {};

    auto const hwnd = CreateWindowA(
        windowName, windowName, WS_OVERLAPPEDWINDOW, 0, 0, width, height, NULL, NULL, hInstance, NULL);

    if (!hwnd) return {};

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    return Handle{reinterpret_cast<void*>(hwnd)};
}

bool Window::RunOSUpdateLoop() {
    static MSG msg{};

    bool const message = GetMessage(&msg, NULL, 0, 0);

    if (!message) return false;

    TranslateMessage(&msg);
    DispatchMessage(&msg);

    return true;
}
} // namespace oss
