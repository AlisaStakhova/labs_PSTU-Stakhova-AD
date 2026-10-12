#include <iostream> #include <cmath> using namespace std;
int main() {
    double sum = 0.0; double factorial = 1.0; double an;
    for (int n = 1; n <= 13; n++)
    {
        factorial *= n;
        an = log(factorial) / (n * n);
        sum += an;
    }

    cout << "Результат: " << sum << endl;

    return 0;
}