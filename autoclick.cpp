#include <windows.h>
#include <iostream>
int x;
int y;
bool started = false;
void start() {
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
            Sleep(10);
        }
    }
}

int main()
{
    std::cout << "Press F10 to toggle autoclicker.\n";
    start();
}
