#include <iostream>

int SumA[21], SumB[21];
int main()
{
	int a, n, m, x;
	std::cin >> a >> n >> m >> x;
	SumA[1] = SumA[2] = 1;
	SumA[3]			  = 2;
	for (int i = 4; i < n; i++)
	{
		SumA[i] = SumA[i - 1] + SumA[i - 2] - 1;
		SumB[i] = SumB[i - 1] + SumB[i - 2] + 1;
	}
	int b = (m - a * SumA[n - 1]) / SumB[n - 1];
	std::cout << a * SumA[x] + b * SumB[x] << "\n";

	return 0;
}