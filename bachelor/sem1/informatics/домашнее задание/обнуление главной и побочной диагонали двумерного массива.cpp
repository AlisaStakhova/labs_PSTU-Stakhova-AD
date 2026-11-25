#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Введите размер массива: ";
    cin >> n;

    if (n <= 0)
        return 0;

    int** arr = new int* [n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    cout << "Введите элементы массива:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i][i] = 0;
        arr[i][n - 1 - i] = 0;
    }

    cout << "Результат:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}