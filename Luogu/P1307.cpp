#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int num, ans = 0;
    scanf("%d", &num);

    while (num != 0)
    {
        ans = ans * 10 + num % 10;
        num /= 10;
    }

    printf("%d\n", ans);
    system("pause");

    return 0;
}