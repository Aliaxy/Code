#include <iostream>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int Num[3];
	std::cin >> Num[0] >> Num[1] >> Num[2];
	std::sort(Num, Num + 3);
	for (int i = 0; i < 3; i++)
	{
		char s;
		std::cin >> s;
		if (i == 2)
			std::cout << Num[s - 'A'];
		else
			std::cout << Num[s - 'A'] << ' ';
	}

	return 0;
}