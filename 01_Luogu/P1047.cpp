#include <iostream>
using namespace std;

int main()
{
    int l, //! ��·����
        n; //! ������Ŀ

    cin >> l >> n;
    int *tree = new int[l + 1]; //* ����һ������

    //! 1�������� 0����û��
    for (int i = 0; i <= l; i++) //* ��������Ԫ��ȫ����Ϊ 1
    {
        tree[i] = 1;
    }
    int x, y; //? ��ʼ�����ֹ��

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        for (int j = x; j <= y; j++) //! ����ʼ�㵽��ֹ�������ȫ���滻Ϊ 0
        {
            tree[j] = 0;
        }
    }
    int sum = 0;

    for (int i = 0; i <= l; i++) //* ͳ�������� 1 �ĸ���
    {
        sum += tree[i];
    }
    cout << sum << endl;

    system("pause");
    return 0;
}