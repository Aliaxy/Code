#include <iostream>
#include <vector>
#include <algorithm>

struct StuInfo
{
	int ID, Chinese, Sum;
};
std::vector<StuInfo> Student;

bool Cmp(StuInfo x, StuInfo y)
{
	if (x.Sum == y.Sum)
	{
		if (x.Chinese == y.Chinese)
			return x.ID < y.ID;
		return x.Chinese > y.Chinese;
	}
	return x.Sum > y.Sum;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		Student.push_back({i + 1, a, a + b + c});
	}
	std::sort(Student.begin(), Student.end(), Cmp);
	for (int i = 0; i < 5; i++)
		std::cout << Student[i].ID << ' ' << Student[i].Sum << '\n';

	return 0;
}