#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int num,
        a,
        temp = 0,
        l = 0,
        sum = 0;
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &a);
        if (a < temp)
            l = 1;
        if (temp < a && l == 1)
        {
            l = 0;
            sum++;
        }
        temp = a;
    }

    printf("%d\n", sum);

    system("pause");

    return 0;
}