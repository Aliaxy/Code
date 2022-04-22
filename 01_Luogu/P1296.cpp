#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, d, j = 1, sum = 0;

    cin >> n >> d;

    int *row = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> row[i];
    }
    sort(row, row + n);
    for (int i = 0; i < n; i++)
    {
        while (n > j && row[j] - row[i] <= d)
            j++;
        j--;
        sum += j - i;
    }

    cout << sum << endl;
    system("pause");

    return 0;
}