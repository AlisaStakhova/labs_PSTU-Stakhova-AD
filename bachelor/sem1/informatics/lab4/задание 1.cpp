// Сумма элементов каждой строки матрицы, вывод по правому краю
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const int N = 4; // строки
    const int M = 5; // столбцы

    // матрицу задаю вручную
    int matrix[N][M] = {
        {12, -5, 140, 7, -38},
        {3, 99, -120, 45, 6},
        {-7, 210, 18, -64, 0},
        {55, -1, 8, 300, -19}
    };

    cout << "Матрица и суммы строк:" << endl;

    for (int i = 0; i < N; i++)
    {
        int sum = 0; // для каждой строки считаем заново
        for (int j = 0; j < M; j++)
        {
            cout << setw(5) << matrix[i][j]; // ширина 5, число прижато вправо
            sum += matrix[i][j];
        }
        cout << "  |" << setw(5) << sum << endl;
    }

    return 0;
}