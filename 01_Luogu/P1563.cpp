#include <iostream>
#include <string>
#include <vector>

struct Node
{
	bool State;
	std::string Name;
	;
};
std::vector<Node> People;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int PeopleNum, OrderNum;
	std::cin >> PeopleNum >> OrderNum;
	for (int i = 0; i < PeopleNum; i++)
	{
		bool flag;
		std::string str;
		std::cin >> flag >> str;
		People.push_back({flag, str});
	}
	int now = 0;
	while (OrderNum--)
	{
		int x, y;
		std::cin >> x >> y;
		if (People[now].State ^ x)
			now = (now + y) % PeopleNum;
		else
			now = (now + PeopleNum - y) % PeopleNum;
	}
	std::cout << People[now].Name << '\n';

	return 0;
}