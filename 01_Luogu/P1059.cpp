#include <iostream>
using namespace std;

int main()
{
    int arr[1001] = {0}, //! ������洢���������ֵ
        k = 0,
        n,
        num;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (arr[num] == 0) //* �ж�����ֵ��λ���Ƿ��Ѿ���ռ ������
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