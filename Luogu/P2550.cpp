#include <iostream>

int Result[7], Match[7];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int PageNum;
	std::cin >> PageNum;
	for (int i = 0; i < 7; i++)
		std::cin >> Match[i];
	while (PageNum--)
	{
		int cnt = 7;
		for (int i = 0; i < 7; i++)
		{
			int x;
			std::cin >> x;
			for (int j = 0; j < 7; j++)
				if (x == Match[j])
					cnt--;
		}
		if (cnt < 7)
			Result[cnt]++;
	}
	for (int i = 0; i < 7; i++)
		std::cout << Result[i] << ' ';

	return 0;
}