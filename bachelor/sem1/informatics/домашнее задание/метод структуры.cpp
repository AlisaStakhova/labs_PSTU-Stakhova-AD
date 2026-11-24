#include <iostream>
#include <string>
using namespace std;

struct Human
{
    string name;
    int age;

    bool isAdult()
    {
        return age >= 18;
    }
};

int main()
{
    Human person;

    cout << "Введите имя: ";
    cin >> person.name;

    cout << "Введите возраст: ";
    cin >> person.age;

    if (person.isAdult())
    {
        cout << person.name << " совершеннолетний";
    }
    else
    {
        cout << person.name << " несовершеннолетний";
    }

    return 0;
}