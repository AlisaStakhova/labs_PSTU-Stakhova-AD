#define _CRT_SECURE_NO_WARNINGS // чтобы Visual Studio не ругалась на fopen
// Структура "Автомобиль": марка, серийный номер, регистрационный номер,
// год выпуска.
// Удалить 3 элемента из начала файла, добавить элемент после элемента
// с указанным регистрационным номером.
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <clocale>
#ifdef _WIN32
#include <windows.h> // для SetConsoleCP
#endif
using namespace std;

struct Car
{
    char marka[20];   // марка
    char serial[20];  // серийный номер
    char regnum[15];  // регистрационный номер
    int year;         // год выпуска
};

const char FNAME[] = "cars.dat"; // основной файл
const char TNAME[] = "temp.dat"; // вспомогательный файл

// ввод строки с пробелами (вместо gets)
void readStr(char s[], int size)
{
    cin >> ws; // пропустить пробелы и Enter
    cin.getline(s, size);
    if (cin.fail()) // строка длиннее поля, лишнее отбрасывается
    {
        cin.clear(); // снять ошибку ввода
        cin.ignore(1000, '\n'); // выбросить остаток строки
    }
}

// ввод одной структуры с клавиатуры
Car inputCar()
{
    Car c = {}; // все поля обнуляются
    cout << "Марка: ";
    readStr(c.marka, 20);
    cout << "Серийный номер: ";
    readStr(c.serial, 20);
    cout << "Регистрационный номер: ";
    readStr(c.regnum, 15);
    cout << "Год выпуска: ";
    while (!(cin >> c.year)) // введено не число
    {
        cin.clear(); // снять ошибку ввода
        cin.ignore(1000, '\n'); // убрать неверный ввод
        cout << "Введите год числом: ";
    }
    cin.ignore(1000, '\n'); // остаток строки после числа
    return c;
}

// формирование файла, возвращает число записей
int makeFile(const char *name)
{
    FILE *f = fopen(name, "wb");
    if (f == NULL)
    {
        cout << "Ошибка открытия файла " << name << endl;
        return 0;
    }
    int k = 0;
    char ans;
    do
    {
        cout << "Автомобиль " << k + 1 << endl;
        Car c = inputCar();
        if (fwrite(&c, sizeof(Car), 1, f) != 1) // не записалась структура
        {
            cout << "Ошибка записи в файл" << endl;
            break;
        }
        k++;
        if (k < 5) // меньше 5 записей файл не формируется
            ans = 'y';
        else
        {
            cout << "Продолжить ввод? (y/n) ";
            cin >> ans; // берется первая буква ответа
            cin.ignore(1000, '\n');
        }
    } while (ans == 'y' || ans == 'Y');
    fclose(f);
    return k;
}

// печать файла
void printFile(const char *name)
{
    FILE *f = fopen(name, "rb");
    if (f == NULL)
    {
        cout << "Ошибка открытия файла " << name << endl;
        return;
    }
    Car c;
    int k = 0;
    cout << " N  Марка              Серийный номер       "
         << "Рег. номер     Год" << endl;
    while (fread(&c, sizeof(Car), 1, f) == 1) // пока запись прочитана
    {
        k++;
        // setw ширина столбца, left влево
        cout << setw(2) << k << "  " << left << setw(19) << c.marka
             << setw(21) << c.serial << setw(15) << c.regnum
             << right << c.year << endl;
    }
    if (ferror(f)) // была ли ошибка чтения
        cout << "Ошибка чтения файла" << endl;
    if (k == 0)
        cout << "Файл пуст" << endl;
    fclose(f);
}

// удаление n записей из начала файла через вспомогательный файл
void deleteFirst(const char *name, int n)
{
    FILE *f = fopen(name, "rb");
    if (f == NULL)
    {
        cout << "Ошибка открытия файла " << name << endl;
        return;
    }
    FILE *t = fopen(TNAME, "wb");
    if (t == NULL)
    {
        cout << "Ошибка открытия файла " << TNAME << endl;
        fclose(f);
        return;
    }
    Car c;
    int k = 0;
    bool err = false; // была ли ошибка записи
    while (!err && fread(&c, sizeof(Car), 1, f) == 1)
    {
        k++;
        if (k > n) // первые n записей не переписываются
        {
            if (fwrite(&c, sizeof(Car), 1, t) != 1)
                err = true;
        }
    }
    fclose(f);
    fclose(t);
    if (err) // основной файл не меняется
    {
        cout << "Ошибка записи в файл " << TNAME << endl;
        return;
    }
    // temp.dat становится основным файлом
    if (remove(name) != 0 || rename(TNAME, name) != 0)
    {
        cout << "Ошибка замены файла " << name << endl;
        return;
    }
    if (k < n)
        cout << "В файле было меньше " << n
             << " записей, удалены все" << endl;
    else
        cout << "Удалено записей: " << n << endl;
}

// поиск записи по регистрационному номеру
// возвращает номер записи в файле (с 0) или -1, если не найдена
int findReg(const char *name, const char *reg)
{
    FILE *f = fopen(name, "rb");
    if (f == NULL)
    {
        cout << "Ошибка открытия файла " << name << endl;
        return -1;
    }
    Car c;
    int i = 0, pos = -1;
    while (fread(&c, sizeof(Car), 1, f) == 1)
    {
        if (strcmp(c.regnum, reg) == 0)
        {
            pos = i;
            break;
        }
        i++;
    }
    fclose(f);
    return pos;
}

// добавление записи после записи с номером reg через вспомогательный файл
void addAfter(const char *name, const char *reg)
{
    int pos = findReg(name, reg);
    if (pos == -1)
    {
        cout << "Автомобиль с номером " << reg
             << " не найден, запись не добавлена" << endl;
        return;
    }
    cout << "Введите данные нового автомобиля" << endl;
    Car nc = inputCar();
    FILE *f = fopen(name, "rb");
    if (f == NULL)
    {
        cout << "Ошибка открытия файла " << name << endl;
        return;
    }
    FILE *t = fopen(TNAME, "wb");
    if (t == NULL)
    {
        cout << "Ошибка открытия файла " << TNAME << endl;
        fclose(f);
        return;
    }
    Car c;
    int i = 0;
    bool err = false; // была ли ошибка записи
    while (!err && fread(&c, sizeof(Car), 1, f) == 1)
    {
        if (fwrite(&c, sizeof(Car), 1, t) != 1)
            err = true;
        if (i == pos) // после найденной записи пишется новая
        {
            if (fwrite(&nc, sizeof(Car), 1, t) != 1)
                err = true;
        }
        i++;
    }
    fclose(f);
    fclose(t);
    if (err) // основной файл не меняется
    {
        cout << "Ошибка записи в файл " << TNAME << endl;
        return;
    }
    if (remove(name) != 0 || rename(TNAME, name) != 0)
    {
        cout << "Ошибка замены файла " << name << endl;
        return;
    }
    cout << "Запись добавлена после записи " << pos + 1 << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
#ifdef _WIN32 // на Windows консоль в кодировке 1251
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
    char reg[15];

    cout << "Формирование файла (не меньше 5 записей)" << endl;
    int n = makeFile(FNAME);
    cout << "Записано в файл: " << n << endl;
    cout << endl << "Содержимое файла" << endl;
    printFile(FNAME);

    cout << endl << "Удаление 3 записей из начала файла" << endl;
    deleteFirst(FNAME, 3);
    printFile(FNAME);

    cout << endl
         << "Регистрационный номер, после которого добавить запись: ";
    readStr(reg, 15);
    addAfter(FNAME, reg);
    cout << endl << "Содержимое файла" << endl;
    printFile(FNAME);
    return 0;
}
