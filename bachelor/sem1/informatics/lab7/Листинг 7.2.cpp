#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdarg>
#include <clocale>
#ifdef _WIN32
#include <windows.h> // для SetConsoleCP
#endif
using namespace std;

const double PI = 3.14159265358979;

// угол треугольника со сторонами a, b, c (в градусах),
// лежащий против стороны c, по теореме косинусов
double angle(double a, double b, double c)
{
    return acos((a * a + b * b - c * c) / (2 * a * b)) * 180 / PI;
}

// существует ли треугольник со сторонами a, b, c
bool triangle(double a, double b, double c)
{
    return a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a;
}

// углы n-угольника, k - число параметров, n = (k + 3) / 2
// сначала n сторон A1A2, ..., AnA1, потом диагонали A1A3, ..., A1A(n-1)
// угол считается как сумма углов треугольников A1 Ai A(i+1)
void angles(int k, ...)
{
    const int MAX = 20;
    double s[MAX + 1]; // s[i] - сторона AiA(i+1)
    double r[MAX + 1]; // r[i] - отрезок A1Ai
    double u[MAX + 1]; // u[i] - угол при вершине Ai
    int n = (k + 3) / 2;
    if (k < 3 || k % 2 == 0 || n > MAX)
    {
        cout << "Неверное количество параметров: " << k << endl;
        return;
    }
    va_list p; // список параметров
    va_start(p, k); // p на первый после k
    for (int i = 1; i <= n; i++)
        s[i] = va_arg(p, double); // очередной double, p дальше
    r[2] = s[1]; // A1A2 это сторона s1
    for (int i = 3; i <= n - 1; i++)
        r[i] = va_arg(p, double);
    r[n] = s[n]; // A1An это сторона sn
    va_end(p); // конец чтения

    cout << fixed << setprecision(4); // 4 знака после точки
    cout << "n = " << n << ", параметров " << k << endl;
    cout << "Стороны:";
    for (int i = 1; i <= n; i++)
        cout << " " << s[i];
    cout << endl;
    if (n > 3)
    {
        cout << "Диагонали из A1:";
        for (int i = 3; i <= n - 1; i++)
            cout << " " << r[i];
        cout << endl;
    }

    for (int i = 1; i <= n; i++)
        u[i] = 0;
    for (int i = 2; i <= n - 1; i++) // треугольник A1 Ai A(i+1)
    {
        if (!triangle(r[i], s[i], r[i + 1]))
        {
            cout << "Треугольник A1 A" << i << " A" << i + 1
                 << " не существует, углы найти нельзя" << endl << endl;
            return;
        }
        // угол против третьего аргумента
        u[1] += angle(r[i], r[i + 1], s[i]);
        u[i] += angle(r[i], s[i], r[i + 1]);
        u[i + 1] += angle(r[i + 1], s[i], r[i]);
    }

    double sum = 0;
    cout << setprecision(2); // углы с 2 знаками
    cout << "Углы:";
    for (int i = 1; i <= n; i++)
    {
        cout << " A" << i << "=" << u[i];
        sum += u[i];
    }
    cout << endl;
    cout << "Сумма углов " << sum;
    cout << ", (n - 2)*180 = " << (n - 2) * 180 << endl << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    // консоль Windows в кодировке 1251
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
    // числа пишутся с точкой (5.0, а не 5), иначе va_arg(p, double)
    // прочитает целое число неверно
    cout << "Треугольник" << endl;
    angles(3, 5.0, 6.0, 7.0);

    cout << "Шестиугольник" << endl;
    angles(9, 5.0990, 5.0, 4.1231, 5.0, 5.8310, 6.0828,
              9.2195, 11.6619, 10.8167);

    cout << "Семиугольник" << endl;
    angles(11, 4.4721, 4.1231, 5.0, 4.1231, 5.3852, 5.6569, 5.0990,
               8.0623, 11.4018, 12.2066, 10.2956);

    cout << "Треугольник с неверными сторонами" << endl;
    angles(3, 1.0, 2.0, 5.0);
    return 0;
}
