#include <iostream>
#include <windows.h>

using namespace std;

//инверсия чисел

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    string ribbon = "10110_";
    string mode = "q0";
    int pos = 0;

    cout << "Исходная лента: " << ribbon.substr(0, ribbon.length() - 1) << endl;

    while (mode != "q_z")
    {
        char symbol = ribbon[pos];

        if (mode == "q0")
        {
            switch (symbol)
            {
            case '0':
                ribbon[pos] = '1';
                pos++;
                break;
            case '1':
                ribbon[pos] = '0';
                pos++;
                break;
            case '_':
                mode = "q_z";
                break;
            }
        }
    }
    cout << "Результат: " << ribbon.substr(0, ribbon.length() - 1) << endl;

    return 0;
}