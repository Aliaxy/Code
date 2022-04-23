#include <cstdio>
#include <stdlib.h>

int compare(int *, int);

int main()
{
	int n,
		*rank,
		i;
	scanf("%d", &n);
	rank = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		scanf("%d", &rank[i]);

	for (i = 0; i < n - 1; i++)
		printf("%d ", compare(rank, i));
	printf("%d\n", compare(rank, i));

	free(rank);
	return 0;
}

int compare(int *p, int i)
{
	int count = 0;
	for (int j = 0; j < i; j++)
	{
		if (p[i] > p[j])
			count++;
	}
	return count;
}