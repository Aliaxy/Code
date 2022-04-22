#include <iostream>
using namespace std;

int main()
{
    int l,
        r,
        num,
        sum = 0;
    cin >> l >> r;

    for (int i = l; i <= r; i++)
    {
        num = i;
        while (num)
        {
            if (num % 10 == 2)
                sum++;
            num /= 10;
        }
    }

    cout << sum << endl;

    system("pause");

    return 0;
}