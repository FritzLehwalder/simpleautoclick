#include <windows.h>
#include <iostream>
bool started = false;
int timer = 10;
void start() {
    std:cout << "Enter ms between click: \t";
    std:cin >> timer;

    // testing
    std:cout >> timer;

    std:cout << "\n";'
    while (true) {
        if (GetAsyncKeyState(VK_F10)) {
            started = !started;
            if(started) std::cout << "Autoclicker has started.\n";
            if(!started) std::cout << "Autoclicker has stopped.\n";
            Sleep(400);
        }
        if (started) {
            mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
            Sleep(timer);
        }
    }
}

int main()
{
    std::cout << "Press F10 to toggle autoclicker.\n";
    start();
}
