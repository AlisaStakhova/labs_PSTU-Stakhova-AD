#include <iostream>
#include <string>
using namespace std;

struct Human
{
    string name;
    int age;
    double weight;
};

int main()
{
    Human person;

    cout << "Введите имя: ";
    cin >> person.name;

    cout << "Введите возраст: ";
    cin >> person.age;

    cout << "Введите вес: ";
    cin >> person.weight;

    cout << endl;
    cout << "Информация о человеке:" << endl;

    cout << "Имя: " << person.name << endl;
    cout << "Возраст: " << person.age << endl;
    cout << "Вес: " << person.weight << endl;

    return 0;
}