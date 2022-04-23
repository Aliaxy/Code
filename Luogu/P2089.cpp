#include <iostream>

const int MAX = 5e4;
int aa[MAX][10];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	if (n < 10 || n > 30)
		std::cout << 0 << '\n';
	else if (n == 10)
	{
		std::cout << 1 << '\n';
		for (int i = 0; i < 10; i++)
			std::cout << 1 << ' ';
	}
	else
	{
		int sum = 0, cnt = 0;
		for (int a = 1; a <= 3; a++)
			for (int b = 1; b <= 3; b++)
				for (int c = 1; c <= 3; c++)
					for (int d = 1; d <= 3; d++)
						for (int e = 1; e <= 3; e++)
							for (int f = 1; f <= 3; f++)
								for (int g = 1; g <= 3; g++)
									for (int h = 1; h <= 3; h++)
										for (int i = 1; i <= 3; i++)
											for (int j = 1; j <= 3; j++)
												if (a + b + c + d + e + f + g + h + i + j == n)
												{
													aa[sum][cnt++] = a;
													aa[sum][cnt++] = b;
													aa[sum][cnt++] = c;
													aa[sum][cnt++] = d;
													aa[sum][cnt++] = e;
													aa[sum][cnt++] = f;
													aa[sum][cnt++] = g;
													aa[sum][cnt++] = h;
													aa[sum][cnt++] = i;
													aa[sum++][cnt++] = j;
													cnt = 0;
												}
		std::cout << sum << '\n';
		for (int i = 0; i < sum; i++)
		{
			for (int j = 0; j < 10; j++)
				std::cout << aa[i][j] << ' ';
			std::cout << '\n';
		}
	}

	return 0;
}