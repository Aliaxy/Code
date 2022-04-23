#include <iostream>
#include <cstdio>

int main()
{
	int m, n,
		arr[10] = {0},
		temp;
	std::cin >> m >> n;

	for (int i = m; i <= n; i++)
	{
		temp = i;
		while (temp)
		{
			arr[temp % 10]++;
			temp /= 10;
		}
	}
	for (int i = 0; i < 9; i++)
		std::cout << arr[i] << " ";
	std::cout << arr[9] << std::endl;
	return 0;
}