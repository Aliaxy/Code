#include <iostream>
using namespace std;

int main()
{
    int n,
        arr[1001],
        sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[i])
                sum++;
        }
    }
    cout << sum << endl;

    system("pause");

    return 0;
}