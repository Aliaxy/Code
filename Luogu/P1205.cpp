#include <iostream>

int n;
char a[15][15], b[15][15], c[15][15], d[15][15];

bool work1()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			b[j][n - i + 1] = a[i][j];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (b[i][j] != c[i][j])
				return 0;
	return 1;
}
bool work2()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			b[n - i + 1][n - j + 1] = a[i][j];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (b[i][j] != c[i][j])
				return 0;
	return 1;
}
bool work3()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			b[n - j + 1][i] = a[i][j];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (b[i][j] != c[i][j])
				return 0;
	return 1;
}
bool work4()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			b[i][n - j + 1] = a[i][j];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (b[i][j] != c[i][j])
				return 0;
	return 1;
}
bool work5()
{
	work4();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = b[i][j];
	if (work1())
		return 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = b[i][j];
	if (work2())
		return 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = b[i][j];
	if (work3())
		return 1;
	return 0;
}
bool work6()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (b[i][j] != c[i][j])
				return 0;
	return 1;
}
void work()
{
	if (work1())
	{
		std::cout << 1;
		return;
	}
	if (work2())
	{
		std::cout << 2;
		return;
	}
	if (work3())
	{
		std::cout << 3;
		return;
	}
	if (work4())
	{
		std::cout << 4;
		return;
	}
	if (work5())
	{
		std::cout << 5;
		return;
	}
	if (work6())
	{
		std::cout << 6;
		return;
	}
	std::cout << 7;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			std::cin >> a[i][j];
			d[i][j] = a[i][j];
		}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			std::cin >> c[i][j];
	work();
	return 0;
}