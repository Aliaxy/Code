#include <iostream>
using namespace std;

int arr[40000];

int main()
{
    int n,
        num,
        i,
        s = 0,
        p = 0;
    bool flag = false;

    cin >> n;

    while (s < n * n)
    {
        cin >> num;
        for (i = p; i < p + num; i++)
            arr[i] = flag;
        p = i;
        flag = !flag;
        s += num;
    }
    p = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[p];
            p++;
        }
        cout << endl;
    }
    system("pause");
    return 0;
}