#define _CRT_SECURE_NO_WARNINGS // чтобы Visual Studio не ругалась на strcpy
// Удалить из строки все слова, которые не являются идентификаторами
#include <iostream>
#include <cstring>
#include <clocale>
#ifdef _WIN32
#include <windows.h> // для SetConsoleCP
#endif
using namespace std;

// проверка, является ли слово w идентификатором: первый символ
// латинская буква или _, остальные латинские буквы, цифры или _
bool isIdent(char w[])
{
    if (w[0] == '\0')
        return false;
    for (int i = 0; w[i] != '\0'; i++)
    {
        char c = w[i];
        bool letter = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
                      || c == '_';
        bool digit = c >= '0' && c <= '9';
        if (!letter && !(digit && i > 0)) // цифра не может быть первой
            return false;
    }
    return true;
}

// удаление из строки s слов, которые не являются идентификаторами,
// оставшиеся слова записываются через один пробел, в конце точка
void delWords(char s[])
{
    char t[258], res[258] = ""; // с запасом на точку и '\0'
    strcpy(t, s); // копия, strtok портит строку
    int n = strlen(t);
    while (n > 0 && t[n - 1] == ' ') // пробелы в конце строки
        n--;
    if (n > 0 && t[n - 1] == '.') // точка в конце текста
        n--;
    t[n] = '\0';
    char *w = strtok(t, " "); // первое слово
    while (w != NULL)
    {
        if (isIdent(w))
        {
            if (res[0] != '\0')
                strcat(res, " ");
            strcat(res, w);
        }
        w = strtok(NULL, " "); // NULL значит продолжить ту же строку
    }
    strcat(res, ".");
    strcpy(s, res);
}

int main()
{
    setlocale(LC_ALL, "Russian");
#ifdef _WIN32 // на Windows консоль в кодировке 1251
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
    char s[258]; // с запасом, читается не больше 255 символов
    cout << "Введите строку (не более 255 символов, в конце точка):";
    cout << endl;
    cin.getline(s, 256);
    if (cin.fail())
    {
        cout << "Строка длиннее 255 символов" << endl;
        return 1;
    }
    delWords(s);
    if (strcmp(s, ".") == 0)
        cout << "Идентификаторов в строке нет, все слова удалены" << endl;
    else
    {
        cout << "Строка без слов, которые не являются идентификаторами:";
        cout << endl;
        cout << s << endl;
    }
    return 0;
}
