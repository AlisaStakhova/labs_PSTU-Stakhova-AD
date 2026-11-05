// Сортировка вставками
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    const int N = 7;
    int A[N] = { 6, 2, 9, 4, 1, 7, 3 };

    cout << "Исходный массив: ";
    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;

    for (int i = 1; i < N; i++)
    {
        int y = A[i]; // очередной элемент в буфер
        int j = i - 1;
        bool F = false; // место для y пока не нашли
        while (j >= 0 && F == false)
        {
            if (A[j] > y)
            {
                A[j + 1] = A[j]; // сдвигаем вправо
                j--;
            }
            else
                F = true;
        }
        A[j + 1] = y;
    }

    cout << "Отсортированный массив: ";
    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}