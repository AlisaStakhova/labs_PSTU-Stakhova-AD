// Сортировка выбором
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

    // сортировка выбором по возрастанию
    for (int i = 0; i < N - 1; i++)
    {
        int k = i; // индекс минимума среди A[i]..A[N-1]
        for (int j = i + 1; j < N; j++)
        {
            if (A[j] < A[k])
                k = j;
        }
        if (k != i) // минимум не на своем месте, меняем через y
        {
            int y = A[i];
            A[i] = A[k];
            A[k] = y;
        }
    }

    cout << "Отсортированный массив: ";
    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}