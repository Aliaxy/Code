#include <iostream>
using namespace std;

int main()
{
    int budget,
        differ,
        sum = 0,
        remain = 300,
        k = 0;

    for (int i = 1; i <= 12 && k == 0; i++)
    {
        cin >> budget;
        if (remain < budget)
        {
            k = -i;
        }
        else
        {
            differ = remain - budget;
            remain = differ % 100 + 300;
            sum += differ / 100 * 100;
        }
    }
    if (k != 0)
    {
        cout << k << endl;
    }
    else
    {
        cout << remain - 300 + sum * 1.2 << endl;
    }

    system("pause");
    return 0;
}