#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

struct StuInfo
{
	std::string Name;
	int Socre[3], SocreSum;
};
struct Close
{
	std::string a, b;
	bool operator<(const Close &x)
	{
		if (a == x.a)
			return b < x.b;
		return a < x.a;
	}
};

std::vector<StuInfo> Student;
std::vector<Close> Match;

bool IsClose(int x, int y)
{
	for (int i = 0; i < 3; i++)
		if (std::abs(Student[x].Socre[i] - Student[y].Socre[i]) > 5)
			return false;
	if (std::abs(Student[x].SocreSum - Student[y].SocreSum) > 10)
		return false;
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::string str;
		int a, b, c;
		std::cin >> str >> a >> b >> c;
		Student.push_back({str, a, b, c, a + b + c});
	}
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (IsClose(i, j))
			{
				if (Student[i].Name > Student[j].Name)
					Match.push_back({Student[j].Name, Student[i].Name});
				else
					Match.push_back({Student[i].Name, Student[j].Name});
			}

	for (int i = 0; i < Match.size(); i++)
		std::cout << Match[i].a << ' ' << Match[i].b << '\n';

	return 0;
}