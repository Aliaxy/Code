#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Info
{
	std::string Num;
	int ID;
};

std::vector<Info> Page;

bool Cmp(Info x, Info y)
{
	if (x.Num.size() == y.Num.size())
		return x.Num > y.Num;
	return x.Num.size() > y.Num.size();
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::string x;
		std::cin >> x;
		Page.push_back({x, i + 1});
	}
	std::sort(Page.begin(), Page.end(), Cmp);
	std::cout << Page[0].ID << '\n';
	std::cout << Page[0].Num << '\n';

	return 0;
}