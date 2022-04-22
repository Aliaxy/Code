#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int Day;
	std::cin >> Day;
	int sum = 0, cnt = 0;
	for (int i = 1; cnt < Day; i++)
	{
		for (int j = 0; j < i && cnt < Day; j++)
		{
			sum += i;
			cnt++;
		}
	}
	std::cout << sum << '\n';

	return 0;
}