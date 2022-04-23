#include <iostream>

int A[1005], B[1005];

int main()
{
	int n;
	std::cin >> n;
	A[0] = B[0] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 100; j++)
			B[j] *= i;
		for (int j = 0; j < 100; j++)
			if (B[j] > 9)
			{
				B[j + 1] += B[j] / 10;
				B[j] %= 10;
			}
		for (int j = 0; j < 100; j++)
		{
			A[j] += B[j];
			if (A[j] > 9)
			{
				A[j + 1] += A[j] / 10;
				A[j] %= 10;
			}
		}
	}

	for (int i = 100; i >= 0; i--)
		if (A[i] != 0)
		{
			for (int j = i; j >= 0; j--)
			{
				std::cout << A[j];
			}
			break;
		}

	return 0;
}