#include <iostream>
#include <vector>
#include <algorithm>

struct Info
{
	int ID, Score;
};
std::vector<Info> Person;

bool Cmp(Info x, Info y)
{
	if (x.Score == y.Score)
		return x.ID < y.ID;
	return x.Score > y.Score;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, PlanNum;
	std::cin >> n >> PlanNum;
	PlanNum = PlanNum * 3 / 2;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		std::cin >> x >> y;
		Person.push_back({x, y});
	}
	std::sort(Person.begin(), Person.end(), Cmp);
	PlanNum--;
	while (Person[PlanNum].Score == Person[PlanNum + 1].Score && PlanNum + 1 < Person.size())
		PlanNum++;
	PlanNum++;
	std::cout << Person[PlanNum - 1].Score << ' ' << PlanNum << '\n';
	for (int i = 0; i < PlanNum; i++)
		std::cout << Person[i].ID << ' ' << Person[i].Score << '\n';

	return 0;
}