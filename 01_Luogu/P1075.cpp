#include <iostream>
using namespace std;

int main()
{
    int num,
        i = 1,
        k = 0;

    cin >> num;

    while (k == 0)
    {
        i++;
        if (num % i == 0)
            k = 1;
    }

    cout << num / i << endl;

    system("pause");

    return 0;
}