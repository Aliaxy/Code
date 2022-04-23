#include <cstdio>

int main()
{
	int num[130], i, j;

	for (i = 0;; i++)
	{
		scanf("%d", &num[i]);
		if (!num[i])
			break;
	}
	i--;
	for (; i > 0; i--)
	{
		printf("%d ", num[i]);
	}
	printf("%d\n", num[i]);

	return 0;
}