#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct StuInfo
{
	std::string Name;
	int Socre[3], SocreSum, ID;
};
std::vector<StuInfo> Student;

bool Cmp(StuInfo x, StuInfo y)
{
	if (x.SocreSum == y.SocreSum)
		return x.ID < y.ID;
	return x.SocreSum > y.SocreSum;
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
		Student.push_back({str, a, b, c, a + b + c, i});
	}
	std::sort(Student.begin(), Student.end(), Cmp);
	std::cout << Student[0].Name << ' ';
	for (int i = 0; i < 3; i++)
		std::cout << Student[0].Socre[i] << ' ';

	return 0;
}