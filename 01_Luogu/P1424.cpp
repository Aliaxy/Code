#include <cstdio>

int main()
{
	int date, n;
	long long sum = 0;

	scanf("%d %d", &date, &n);

	for (int i = 0; i < n; i++)
	{
		if (date == 7)
			date = 1;
		else
		{
			sum += 250 * (date != 6);
			date++;
		}
	}

	printf("%lld\n", sum);

	return 0;
}