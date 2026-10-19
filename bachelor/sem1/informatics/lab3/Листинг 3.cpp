#include <iostream> #include <iomanip> #include <cmath>
using namespace std;
// Вычисление суммы ряда для заданного количества членов double n_sum(double x) { int n = 40; double s = 0;
for (int i = 0; i < n; i++)
{
    s += pow(-1, i) * pow(x, 2 * i + 1) / (2 * i + 1);
}

return s;
}
// Вычисление суммы ряда с заданной точностью double epsilon_sum(double x) { double epsilon = 0.0001; double s = 0; double a = x; int i = 0;
while (abs(a) >= epsilon)
{
    a = pow(-1, i) * pow(x, 2 * i + 1) / (2 * i + 1);

    if (abs(a) < epsilon)
    {
        break;
    }

    s += a;
    i++;
}

return s;
}
int main() { double step = (1.0 - 0.1) / 10.0;
cout << fixed << setprecision(6);

for (double x = 0.1; x <= 1.000001; x += step)
{
    cout << "X = " << x
         << "  SN = " << n_sum(x)
         << "  SE = " << epsilon_sum(x)
         << "  Y = " << atan(x)
         << endl;
}

return 0;
}
