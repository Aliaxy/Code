#include <iostream>
using namespace std;

int main()
{
    int k,
        sub_1, //ǰ��λ
        sub_2, //����λ
        sub_3,
        sum = 0; //����λ

    cin >> k;

    for (int i = 10000; i < 30001; i++)
    {
        sub_1 = i / 100;
        sub_2 = i / 10 % 1000;
        sub_3 = i % 1000;
        if (sub_1 % k == 0 && sub_2 % k == 0 && sub_3 % k == 0)
        {
            cout << i << endl;
            sum++;
        }
    }
    if (sum == 0)
    {
        cout << "No" << endl;
    }
    system("pause");

    return 0;
}