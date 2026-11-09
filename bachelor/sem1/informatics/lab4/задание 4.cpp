// Задача 4. Максимум в двумерном массиве
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const int N = 3; // строки
    const int M = 4; // столбцы
    int matrix[N][M] = { {12, -5, 33,  7},
                        {-8, 21, 50, 14},
                        {15, -3,  9, 26} };

    // пока считаем максимумом первый элемент
    int max = matrix[0][0], maxI = 0, maxJ = 0;

    // выводим матрицу и заодно ищем максимум
    cout << "Матрица:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << setw(4) << matrix[i][j];
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
                maxI = i;
                maxJ = j;
            }
        }
        cout << endl;
    }

    cout << "Максимальный элемент: " << max << endl;
    cout << "Индексы: строка " << maxI
        << ", столбец " << maxJ << endl;
    cout << "Номера: строка " << maxI + 1
        << ", столбец " << maxJ + 1 << endl;

    return 0;
}