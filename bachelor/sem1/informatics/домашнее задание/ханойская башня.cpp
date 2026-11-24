#include <iostream>
using namespace std;

void hanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << "Переместить диск с "
            << a << " на " << c << endl;
        return;
    }

    hanoi(n - 1, a, c, b);

    cout << "Переместить диск с "
        << a << " на " << c << endl;

    hanoi(n - 1, b, a, c);
}

int main()
{
    int n;

    cout << "Введите количество дисков: ";
    cin >> n;

    if (n > 0)
    {
        hanoi(n, 'A', 'B', 'C');
    }

    return 0;
}