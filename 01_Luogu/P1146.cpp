#include <iostream>
using namespace std;

int main()
{
    int num;
    bool arr[1001] = {0};

    cin >> num;
    cout << num << endl; //�൱��ֻ����һöӲ�� ����num��

    for (int i = 1; i <= num; i++) //��ʾ���ǵڼ��η�Ӳ��
    {
        for (int j = 1; j <= num; j++) //��ʾ��ǰ�����ǵڼ�öӲ��
        {
            if (j != i) //! ��ǰ�����͵�ǰӲ�Ҷ�Ӧ�Ļ� ���ֲ��� ����Ӳ�ҷ�
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