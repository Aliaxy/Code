#include <cstdio>

bool Judge(int x)
{
	int a[10] = {0};
	a[x % 10] = a[x / 10 % 10] = a[x / 100] = 1;
	x *= 2;
	a[x % 10] = a[x / 10 % 10] = a[x / 100] = 1;
	x = x / 2 * 3;
	a[x % 10] = a[x / 10 % 10] = a[x / 100] = 1;
	for (int i = 1; i < 10; i++)
		if (a[i] == 0)
			return false;
	return true;
}

int main()
{
	for (int i = 192; i <= 327; i++)
	{
		if (Judge(i))
			printf("%d %d %d\n", i, 2 * i, 3 * i);
	}

	return 0;
}