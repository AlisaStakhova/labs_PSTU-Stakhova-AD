// Сортировка обменом
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

    // N - 1 проходов, на каждом самый маленький всплывает на место A[i]
    for (int i = 0; i < N - 1; i++)
    {
        // идем от конца массива к началу и сравниваем соседей
        for (int j = N - 1; j > i; j--)
        {
            if (A[j - 1] > A[j]) // левый больше правого, меняем через y
            {
                int y = A[j - 1];
                A[j - 1] = A[j];
                A[j] = y;
            }
        }
    }

    cout << "Отсортированный массив: ";
    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}