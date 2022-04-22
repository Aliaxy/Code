#include <iostream>
using namespace std;

int main()
{
    int num;
    bool arr[1001] = {0};

    cin >> num;
    cout << num << endl; //相当于只翻了一枚硬币 故有num次

    for (int i = 1; i <= num; i++) //表示这是第几次翻硬币
    {
        for (int j = 1; j <= num; j++) //表示当前翻的是第几枚硬币
        {
            if (j != i) //! 当前次数和当前硬币对应的话 保持不动 其余硬币翻
            {
                if (arr[j])
                    arr[j] = 0;
                else
                    arr[j] = 1;
            }
            cout << arr[j];
        }
        cout << endl;
    }

    system("pause");

    return 0;
}