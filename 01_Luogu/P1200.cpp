#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int num0 = 1,
        num1 = 1;
    char ch;

    while ((ch = cin.get()) != '\n')
        num0 *= ch - 'A' + 1;
    while ((ch = cin.get()) != '\n')
        num1 *= ch - 'A' + 1;

    if (num0 % 47 == num1 % 47)
        cout << "GO\n";
    else
        cout << "STAY\n";
    system("pause");

    return 0;
}