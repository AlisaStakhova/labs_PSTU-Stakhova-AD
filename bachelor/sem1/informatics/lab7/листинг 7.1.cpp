#include <iostream>
#include <clocale>
#include <cctype>
#ifdef _WIN32
#include <windows.h> // для SetConsoleCP
#endif
using namespace std;

// а) количество отрицательных элементов массива целых чисел
int count(int a[], int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < 0)
            k++;
    return k;
}

// б) количество слов строки, которые начинаются и заканчиваются
// на одну и ту же букву. Слово это буквы подряд, знаки препинания
// и пробелы в слово не входят, регистр букв не учитывается
int count(char s[])
{
    int k = 0;
    char first = 0; // первая буква текущего слова
    for (int i = 0; s[i] != '\0'; i++)
    {
        // (unsigned char) для русских букв
        if (!isalpha((unsigned char)s[i]))
            continue;
        if (i == 0 || !isalpha((unsigned char)s[i - 1])) // начало слова
            first = tolower((unsigned char)s[i]);
        if (!isalpha((unsigned char)s[i + 1])) // конец слова
            if (tolower((unsigned char)s[i]) == first)
                k++;
    }
    return k;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    // консоль Windows в кодировке 1251
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
    const int N = 100;
    int a[N], n;
    char s[256];

    cout << "Введите количество элементов массива (от 1 до " << N << "): ";
    cin >> n;
    if (n < 1 || n > N)
    {
        cout << "Неверное количество элементов" << endl;
        return 1;
    }
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin.ignore(1000, '\n'); // убрать конец строки после чисел

    cout << "Введите строку (в конце точка): ";
    cin.getline(s, 256);

    cout << "Количество отрицательных элементов массива: ";
    cout << count(a, n) << endl;
    cout << "Количество слов, которые начинаются и заканчиваются" << endl;
    cout << "на одну и ту же букву: " << count(s) << endl;
    return 0;
}
