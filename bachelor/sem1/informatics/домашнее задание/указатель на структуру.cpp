#include <iostream>
#include <string>
using namespace std;

struct Book
{
    string title;
    int year;
    double price;
};

int main()
{
    Book book;

    book.title = "Война и мир";
    book.year = 1869;
    book.price = 750.5;

    Book* p = &book;

    cout << p->title << endl;
    cout << p->year << endl;
    cout << p->price << endl;

    return 0;
}