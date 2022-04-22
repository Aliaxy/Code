#include <iostream>
#include <cstdio>
using namespace std;

int find(int *, int, int);

int main()
{
	int n, max = 1, temp;
	scanf("%d", &n);
	int *p = (int *)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);

	for (int i = 0; i < n - 1; i++)
	{
		if (p[i + 1] - p[i] == 1)
		{
			temp = find(p, i, n);
			max = max > temp ? max : temp;
		}
	}

	printf("%d\n", max);

	return 0;
}

int find(int *p, int i, int n)
{
	int max = 1;
	for (; i < n - 1; i++)
	{
		if (p[i + 1] - p[i] == 1)
			max++;
		else
			return max;
	}
	return max;
}