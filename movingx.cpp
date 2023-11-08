#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include <windows.h>
#include <cstdlib>

using namespace std;

const int numRows = 10;
const int numCols = 30;

int row = numRows / 2;
int col = numCols / 2;
int prevRow = row;
int prevCol = col;

int wPressedCount = 0;
int sPressedCount = 0;
int aPressedCount = 0;
int dPressedCount = 0;

void setConsoleColor(int textColor, int bgColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor | (bgColor << 4));
}

void createGame()
{
    cout << "\x1b[H";

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            if (i == row && j == col)
            {
                int randomTextColor = rand() % 16;
                setConsoleColor(randomTextColor, 0);
                cout << "x";
            }
            else
            {
                setConsoleColor(12, 0);
                cout << ".";
            }
        }
        setConsoleColor(7, 0);
        cout << endl;
    }

    cout << "W pressed: " << wPressedCount << " times  " << endl;
    cout << "S pressed: " << sPressedCount << " times  " << endl;
    cout << "A pressed: " << aPressedCount << " times  " << endl;
    cout << "D pressed: " << dPressedCount << " times  " << endl;
}

int main()
{
    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_MAXIMIZE);
    system("cls");
    srand(static_cast<unsigned>(time(NULL)));

    while (true)
    {
        if (_kbhit())
        {
            char key = _getch();

            prevRow = row;
            prevCol = col;

            if (key == 'a' && col > 0)
            {
                col--;
                aPressedCount++;
            }
            else if (key == 'd' && col < numCols - 1)
            {
                col++;
                dPressedCount++;
            }
            else if (key == 'w' && row > 0)
            {
                row--;
                wPressedCount++;
            }
            else if (key == 's' && row < numRows - 1)
            {
                row++;
                sPressedCount++;
            }
            else if (key == 'q')
                break;

            createGame();
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }
    return 0;
}
