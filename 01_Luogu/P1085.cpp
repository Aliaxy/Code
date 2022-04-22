#include <iostream>
using namespace std;

int main()
{
    int school, other,
        sum = 0, max = 0,
        date;

    for (int i = 0; i < 7; i++)
    {
        cin >> school >> other;
        sum = school + other;

        if (sum > 8 && sum > max)
        {
            max = max > sum ? max : sum;
            date = i + 1;
        }
    }

    cout << date << endl;

    system("pause");

    return 0;
}