#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Info
{
	std::string Name;
	int Year, Month, Day, ID;
	bool operator<(const Info &x) const
	{
		if (Year == x.Year)
		{
			if (Month == x.Month)
			{
				if (Day == x.Day)
					return ID > x.ID;
				return Day < x.Day;
			}
			return Month < x.Month;
		}
		return Year < x.Year;
	}
};

std::vector<Info> Student;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::string s;
		int a, b, c;
		std::cin >> s >> a >> b >> c;
		Student.push_back({s, a, b, c, i});
	}
	std::sort(Student.begin(), Student.end());
	for (int i = 0; i < n; i++)
		std::cout << Student[i].Name << '\n';

	return 0;
}