#include <print>
#include <cmath>
using namespace std;

long fac(int n)
{
    if(n == 0) return 1;
    if(n == 1) return 1;
    return n * fac(n - 1);
}

double n_sum(double x)
{
    int n{10};
    double ln3{log(3)};
    int i{1};
    double s{1};
    for(i; i <= n; i++)
    {
        s += (pow(ln3 * x, i) / fac(i));
    }
    return s;
}

double epsilon_sum(double x)
{   
    double epsilon{0.0001};
    double ln3{log(3)};
    int i{1};
    double s{1};
    double a{1};
    for(i; a >= epsilon; i++)
    {
        a = (pow(ln3 * x, i) / fac(i));
        s += a;
    }
    return s;
}

int main()
{
    float step{(1 - 0.1) / 10};
    for(float x{0.1}; x <= 1.01; x += step)
    {
        println("X = {0:.2f} SN = {1:.6f} SE = {2:.6f} Y = {3:.6f}", x, n_sum(x), epsilon_sum(x), pow(3, x));
    }
}