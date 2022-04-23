#include <iostream>
using namespace std;

int main()
{
    int l, //! 马路长度
        n; //! 区域数目

    cin >> l >> n;
    int *tree = new int[l + 1]; //* 建立一个数组

    //! 1代表有树 0代表没树
    for (int i = 0; i <= l; i++) //* 将该数组元素全输入为 1
    {
        tree[i] = 1;
    }
    int x, y; //? 起始点和终止点

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        for (int j = x; j <= y; j++) //! 将起始点到终止点的数组全部替换为 0
        {
            tree[j] = 0;
        }
    }
    int sum = 0;

    for (int i = 0; i <= l; i++) //* 统计数组中 1 的个数
    {
        sum += tree[i];
    }
    cout << sum << endl;

    system("pause");
    return 0;
}