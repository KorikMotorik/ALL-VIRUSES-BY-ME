#include <Windows.h>

#define SCREEN_WIGHT 1920
#define SCREEN_HEIGHT 1080

HICON icons[] = {
    LoadIcon(NULL, IDI_ERROR),
    LoadIcon(NULL, IDI_WARNING),
    LoadIcon(NULL, IDI_INFORMATION),
    LoadIcon(NULL, IDI_QUESTION)
};

size_t s_icon = sizeof(icons);

void DrawIcons() {
    HWND hWnd = GetDesktopWindow();
    HDC hdc = GetWindowDC(hWnd);

    DrawIcon(hdc, rand() % SCREEN_WIGHT, rand() % SCREEN_HEIGHT, icons[rand() % (s_icon / sizeof(HICON))]);

    ReleaseDC(hWnd, hdc);
}

int main() {
    while (1) {
        DrawIcons();
    }
    return 0;
}