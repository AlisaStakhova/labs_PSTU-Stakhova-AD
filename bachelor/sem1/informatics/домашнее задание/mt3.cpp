#include <iostream>
#include <windows.h>

using namespace std;

//перестановка последнего элемента в начало

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    string ribbon = "1101001_";
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
            case '1':
                pos++;
                break;
            case '0':
                pos++;
                break;
            case '_':
                char last_char = ribbon[pos - 1];
                ribbon.insert(0, 1, last_char);
                mode = "q_z";
                break;
            }
        }
    }
    cout << "Результат: " << ribbon.substr(0, ribbon.length() - 2) << endl;

    return 0;
}