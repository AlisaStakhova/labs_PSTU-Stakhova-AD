// Задача 1. Min и max одномерного массива
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const int N = 10;
    int A[N] = { 7, 12, -4, 15, 3, -4, 15, 0, 15, 6 };

    int min = A[0], max = A[0];
    int minIndex = 0, maxIndex = 0; // индексы первых min и max
    int kMin = 0, kMax = 0; // сколько раз встретились

    cout << "Массив: ";
    for (int i = 0; i < N; i++) // один проход по массиву
    {
        cout << A[i] << " ";

        if (A[i] < min) // новый min, считаем заново
        {
            min = A[i];
            minIndex = i;
            kMin = 1;
        }
        else if (A[i] == min) // такой же min, индекс первого не меняем
            kMin++;

        if (A[i] > max) // то же самое для max
        {
            max = A[i];
            maxIndex = i;
            kMax = 1;
        }
        else if (A[i] == max)
            kMax++;
    }
    cout << endl;

    // номер на 1 больше индекса
    cout << "Минимальный элемент: " << min << endl;
    cout << "Первый min: индекс " << minIndex
        << ", номер " << minIndex + 1 << endl;
    cout << "Количество min: " << kMin << endl;
    cout << "Максимальный элемент: " << max << endl;
    cout << "Первый max: индекс " << maxIndex
        << ", номер " << maxIndex + 1 << endl;
    cout << "Количество max: " << kMax << endl;

    return 0;
}