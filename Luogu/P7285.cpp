#include <iostream>
using namespace std;

int main()
{
    int t, n, num, cnt = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cnt = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            if (num)
                cnt++;
        }
        cout << cnt << endl;
        for (int i = 0; i < n - 1; i++)
            cout << "1 ";
        cout << "1\n";
    }

    return 0;
}