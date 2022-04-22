#include <iostream>
#include <cstdio>
using namespace std;

int light[2000000];

int main()
{
	int n, k = 1, count = 0, t;
	double a;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%lf %d", &a, &t);
		for (int j = 1; j <= t; j++)
		{
			if (light[int(j * a)] == 0)
				light[int(j * a)] = 1;
			else
				light[int(j * a)] = 0;
		}
	}

	while (k < 2000000 && count == 0)
	{
		if (light[k] == 1)
		{
			printf("%d\n", k);
			count++;
		}
		k++;
	}

	return 0;
}