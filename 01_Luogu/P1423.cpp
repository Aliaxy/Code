#include <cstdio>

int main()
{
	double n, num = 2;
	int count = 1;
	scanf("%lf", &n);

	while (n > num)
	{
		n -= num;
		num *= 0.98;
		count++;
	}

	printf("%d\n", count);

	return 0;
}