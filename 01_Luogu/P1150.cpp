#include <iostream>
using namespace std;

int main()
{
    int n,   //��ʾ�̵���Ŀ
        k,   //��ʾÿk���̵ٿ��Ի�һ���µ���
        sum; //��ʾ���̵�����
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