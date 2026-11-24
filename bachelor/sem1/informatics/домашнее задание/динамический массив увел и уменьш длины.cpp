#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Введите размер массива: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Ошибка!";
        return 0;
    }

    int* arr = new int[n];

    cout << "Введите элементы массива:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Увеличение массива
    int newSize;

    cout << "Введите новый размер массива: ";
    cin >> newSize;

    if (newSize <= 0)
    {
        delete[] arr;
        cout << "Ошибка!";
        return 0;
    }

    int* newArr = new int[newSize];

    int minSize = n;

    if (newSize < n)
    {
        minSize = newSize;
    }

    for (int i = 0; i < minSize; i++)
    {
        newArr[i] = arr[i];
    }

    delete[] arr;

    arr = newArr;
    n = newSize;

    cout << "Новый массив:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}