#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    double mark;
};

int main()
{
    Student students[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "Введите имя студента: ";
        cin >> students[i].name;

        cout << "Введите возраст: ";
        cin >> students[i].age;

        cout << "Введите средний балл: ";
        cin >> students[i].mark;
    }

    cout << endl;
    cout << "Информация о студентах:" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Имя: " << students[i].name << endl;
        cout << "Возраст: " << students[i].age << endl;
        cout << "Средний балл: " << students[i].mark << endl;
        cout << endl;
    }

    return 0;
}