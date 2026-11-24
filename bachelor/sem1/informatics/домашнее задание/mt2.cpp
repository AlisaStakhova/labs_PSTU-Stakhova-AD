#include <iostream>
#include <windows.h>

using namespace std;

//сложение унарных чисел

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    string ribbon = "111+11";
    string mode = "q0";
    int pos = 0;

    cout << "Исходная лента: " << ribbon << endl;

    while (mode != "q_z")
    {
        char symbol = ribbon[pos];

        if (mode == "q0")
        {
            switch (symbol)
            {
            case '1':
                pos++;
                break;
            case '+':
                ribbon[pos] = '1';
                mode = "q_z";
                break;
            }
        }
    }
    cout << "Результат: " << ribbon.substr(0, ribbon.length() - 1) << endl;

    return 0;
}