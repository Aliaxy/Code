#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int i = 0,
        arr[40000];
    char c;
    while ((c = getchar()) != '\n')
    {
        arr[i] = int(c) - 48;
        i++;
    }

    for (int j = i; j < i * i; j++)
    {
        c = getchar();
        if (c != '\r' && c != '\n')
            arr[j] = int(c) - 48;
        else
            j--;
    }

    printf("%d", i);

    int flag = 0,
        count = 0;
    for (int k = 0; k < i * i; k++)
    {
        if (arr[k] == 0)
        {
            if (flag)
            {
                printf(" %d", count);
                flag = 0;
                count = 0;
            }
            count++;
        }
        else
        {
            if (!flag)
            {
                printf(" %d", count);
                flag = 1;
                count = 0;
            }
            count++;
        }
    }

    if (count > 0)
        printf(" %d\n", count);

    system("pause");
    return 0;
}