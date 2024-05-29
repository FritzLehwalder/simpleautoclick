#include <windows.h>
#include <iostream>

bool started = false;
int timer = 10;
int x = 0;
int y = 0;
bool customPos = false;
POINT curserPos;

static void start() {
while (true) {
    if (GetAsyncKeyState(VK_PAUSE)) {
        started = !started;
        if (started) std::cout << "Autoclicker has started.\n";
        if (!started) std::cout << "Autoclicker has stopped.\n";
        Sleep(400);
    }
    if (GetAsyncKeyState(VK_INSERT)) {
        customPos = !customPos;
        if (customPos) {
            GetCursorPos(&curserPos);
            x = curserPos.x;
            y = curserPos.y;
            std::cout << "Clicking position set to " << curserPos.x << ", " << curserPos.y << ".\n";
        }
        if (!customPos) std::cout << "Click position set to mouse.\n";

        Sleep(400);
    }
    if (started) {
        
        if (!customPos) {
            GetCursorPos(&curserPos);
            x = curserPos.x;
            y = curserPos.y;
        }
        else {
            SetCursorPos(x, y);
        }

        mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
        Sleep(timer);
    }
}
}

int main()
{
    std::cout << "Enter ms between click: ";
    std::cin >> timer;
    std::cout << "===============================================\n";
    std::cout << "Press PAUSE to toggle autoclicker.\n";
    std::cout << "Press INSERT to toggle click on saved position.\n";
    std::cout << "===============================================\n";
    start();
}
