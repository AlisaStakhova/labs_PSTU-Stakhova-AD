#include <iostream>
using namespace std;

int main()
{
    double x,a,b,y;

    cout << "Введите x, a и b: ";
    cin >> x >> a >> b;

    if (x < 0)
    {
        y = a * x + b;
    }
    else if (x <= 10)
    {
        y = ( a + b) / x;
    }
    else
    {
        y = x / ( a * a + b * b * b +1);
    }

    cout << "Результат:" << y << endl;

    return 0;
}