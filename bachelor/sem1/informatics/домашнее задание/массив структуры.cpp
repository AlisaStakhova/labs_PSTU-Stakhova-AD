#include <iostream>
#include <string>
using namespace std;

struct Human
{
    string name;
    int age;
};

int main()
{
    Human people[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "Введите имя: ";
        cin >> people[i].name;

        cout << "Введите возраст: ";
        cin >> people[i].age;
    }

    cout << endl;
    cout << "Список людей:" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << people[i].name << " ";
        cout << people[i].age << endl;
    }

    return 0;
}