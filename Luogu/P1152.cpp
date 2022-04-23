#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,
        differ,
        sum = 0;
    cin >> n;
    int *arr = new int[n];
    int *t = new int[n - 1];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i != 0)
        {
            differ = abs(arr[i] - arr[i - 1]);
            t[i - 1] = differ;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        sum += t[i];
    }
    if (sum == n * (n - 1) / 2)
        cout << "Jolly" << endl;
    else
        cout << "Not jolly" << endl;
    system("pause");

    return 0;
}