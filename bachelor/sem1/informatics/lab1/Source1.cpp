#include <iostream>
using namespace std;
int main() {
    double m, n;
    cout << "Vvedite m: ";
    while (!(cin >> m)) {
        cout << "Oshibka! Vvedite m zanovo: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "Vvedite n: ";
    while (!(cin >> n)) {
        cout << "Oshibka! Vvedite n zanovo: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "1) " << m-- + n << endl;
    cout << "2) " << (++m > -n) << endl;
    cout << "3) " << (--n < ++m) << endl;

    return 0;
}