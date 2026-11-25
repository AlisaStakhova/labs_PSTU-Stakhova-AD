// Найти максимальный из повторяющихся элементов двумерного массива
#include <iostream>
#include <clocale>
#ifdef _WIN32
#include <windows.h> // для SetConsoleCP
#endif
using namespace std;

const int N = 10; // наибольшее число строк и столбцов

// ввод элементов массива с клавиатуры
void input(int a[][N], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Строка " << i + 1 << ": ";
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
}

// печать массива
void print(int a[][N], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout.width(6); // ширина столбца 6
            cout << a[i][j];
        }
        cout << endl;
    }
}

// сколько раз число x встречается в массиве
int countEl(int a[][N], int n, int m, int x)
{
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == x)
                k++;
    return k;
}

// поиск максимального из повторяющихся элементов
// возвращает true, если повторяющиеся элементы есть, ответ в max
bool maxRepeat(int a[][N], int n, int m, int &max) // max по ссылке
{
    bool found = false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (countEl(a, n, m, a[i][j]) >= 2)
                if (!found || a[i][j] > max)
                {
                    max = a[i][j];
                    found = true;
                }
    return found;
}

int main()
{
    setlocale(LC_ALL, "Russian");
#ifdef _WIN32 // на Windows консоль в кодировке 1251
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
    int a[N][N];
    int n = 0, m = 0, max;
    bool found;

    do
    {
        cout << "Введите число строк и столбцов (от 1 до " << N << "): ";
        cin >> n >> m;
        if (!cin) // введены не числа
        {
            cin.clear(); // снять ошибку ввода
            cin.ignore(1000, '\n'); // убрать неверную строку
            n = 0;
        }
    } while (n < 1 || n > N || m < 1 || m > N);

    cout << "Введите элементы массива по строкам" << endl;
    input(a, n, m);

    cout << "Исходный массив" << endl;
    print(a, n, m);

    found = maxRepeat(a, n, m, max);
    if (found)
        cout << "Максимальный из повторяющихся элементов = " << max << endl;
    else
        cout << "Повторяющихся элементов нет" << endl;
    return 0;
}
