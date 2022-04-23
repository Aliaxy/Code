#include <iostream>
using namespace std;

int main()
{
    int n,   //表示烟的数目
        k,   //表示每k个烟蒂可以换一个新的烟
        sum; //表示吸烟的总数
    cin >> n >> k;
    sum = n;

    while (n >= k)
    {
        sum += n / k;
        n = n % k + n / k;
    }

    cout << sum << endl;

    system("pause");

    return 0;
}