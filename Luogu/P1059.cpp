#include <iostream>
using namespace std;

int main()
{
    int arr[1001] = {0}, //! 开数组存储输入的数据值
        k = 0,
        n,
        num;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (arr[num] == 0) //* 判断数据值的位置是否已经被占 即查重
        {
            arr[num] = num;
            k++;
        }
    }

    cout << k << endl;

    for (int j = 0; j < 1001; j++)
    {
        if (arr[j] != 0)
        {
            cout << arr[j] << " ";
        }
    }
    cout << endl;

    system("pause");
    return 0;
}