#include <iostream>
#include <cstdio>
using namespace std;

bool is_prime(int);

int main()
{
    int num;
    scanf("%d", &num);

    for (int i = 4; i <= num; i += 2)
    {
        printf("%d=", i);
        for (int j = 2; j < i; j++)
        {
            if (is_prime(j) == 1 && is_prime(i - j) == 1)
            {
                printf("%d+%d\n", j, i - j);
                break;
            }
        }
    }

    system("pause");

    return 0;
}

bool is_prime(int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}