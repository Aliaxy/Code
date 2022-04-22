#include <iostream>
#include <string>
#include <cstdlib>

std::string State;

void System(int flag)
{
	int win = 0, lose = 0, len = State.size();
	for (int i = 0; i < len; i++)
	{
		if (State[i] == 'W')
			win++;
		else if (State[i] == 'L')
			lose++;
		if ((win >= flag || lose >= flag) && std::abs(win - lose) >= 2)
		{
			std::cout << win << ':' << lose << '\n';
			win = lose = 0;
		}
	}

	std::cout << win << ':' << lose << '\n';
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	char temp;
	while (std::cin >> temp, temp != 'E')
	{
		if (temp == 'W' || temp == 'L')
			State += temp;
	}

	System(11);
	std::cout << '\n';
	System(21);

	return 0;
}