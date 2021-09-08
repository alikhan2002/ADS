#include <iostream>
using namespace std;

int main()
{
    int *a = new int; // Объявление указателя для переменной типа int
    int *b = new int(5); // Инициализация указателя

    *a = 10;
    *b = *a + *b;

    cout << "b is " << *b << endl;

    delete b;
    delete a;

    return 0;
}