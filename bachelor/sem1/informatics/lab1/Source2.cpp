#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a = 100;
    double b = 0.001;

    double x = pow(a - b, 4);
    double y = pow(a, 4) - 4 * pow(a, 3) * b + 6 * pow(a, 2) * pow(b, 2);
    double z = pow(b, 4) - 4 * a * pow(b, 3);

    double result = (x - y) / z;

    cout << result << endl;

    return 0;
}