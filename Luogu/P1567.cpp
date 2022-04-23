#include <iostream>
#include <cstdio>
#include <cstdlib>

int main()
{
	int n, count = 1, max = 1;
	std::cin >> n;
	int *p = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		std::cin >> p[i];

	for (int i = 0; i < n - 1; i++)
	{
		if (p[i + 1] > p[i])
		{
			count++;
		}
		else
		{
			max = max > count ? max : count;
			count = 1;
		}
	}
	if (max < count)
		max = max > count ? max : count;

	std::cout << max << std::endl;

	free(p);

	return 0;
}