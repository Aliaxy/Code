#include <iostream>
#include <algorithm>
#include <cstdio>

int Score[1000];

int main()
{
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> Score[i];
	std::sort(Score, Score + n);
	int sum = 0;
	for (int i = 1; i < n - 1; i++)
		sum += Score[i];
	printf("%.2f\n", (double)sum / (n - 2));

	return 0;
}