#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

struct Info
{
	std::string Name, Pos;
	int Support, Rank, Order;
};
std::vector<Info> Member;
std::map<std::string, int> Match;

bool Cmp1(Info x, Info y)
{
	if (x.Support == y.Support)
		return x.Order < y.Order;
	return x.Support > y.Support;
}

bool Cmp2(Info x, Info y)
{
	if (x.Pos == y.Pos)
	{
		if (x.Rank == y.Rank)
			return x.Order < y.Order;
		return x.Rank > y.Rank;
	}
	return Match[x.Pos] < Match[y.Pos];
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	Match["BangZhu"] = 0;
	Match["FuBangZhu"] = 1;
	Match["HuFa"] = 2;
	Match["ZhangLao"] = 3;
	Match["TangZhu"] = 4;
	Match["JingYing"] = 5;
	Match["BangZhong"] = 6;
	int Num;
	std::cin >> Num;
	for (int i = 0; i < Num; i++)
	{
		std::string x, y;
		int a, b;
		std::cin >> x >> y >> a >> b;
		Member.push_back({x, y, a, b, i});
	}
	std::sort(Member.begin() + 3, Member.end(), Cmp1);
	for (int i = 0; i < Num; i++)
	{
		if (i == 0)
			Member[i].Pos = "BangZhu";
		else if (i == 1 || i == 2)
			Member[i].Pos = "FuBangZhu";
		else if (i == 3 || i == 4)
			Member[i].Pos = "HuFa";
		else if (i >= 5 && i <= 8)
			Member[i].Pos = "ZhangLao";
		else if (i >= 9 && i <= 15)
			Member[i].Pos = "TangZhu";
		else if (i >= 16 && i <= 40)
			Member[i].Pos = "JingYing";
		else
			Member[i].Pos = "BangZhong";
	}
	std::sort(Member.begin(), Member.end(), Cmp2);
	for (int i = 0; i < Num; i++)
		std::cout << Member[i].Name << ' ' << Member[i].Pos << ' ' << Member[i].Rank << '\n';

	return 0;
}