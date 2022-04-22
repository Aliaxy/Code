#include <cstdio>

int main()
{
	int n, t1, t2, num = 0, sum = 0;
	;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &t1, &t2);
		num += t1 + t2 - 8;
		sum += num;
	}
	printf("%d\n", sum);

	return 0;
}