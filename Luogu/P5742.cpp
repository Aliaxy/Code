#include <iostream>

struct StuInfo
{
	int ID, Study, Quality;
	double Sum;
} Student;

bool IsExcellent()
{
	if (Student.Study + Student.Quality > 140 && Student.Sum >= 80)
		return true;
	return false;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int StudentNum;
	std::cin >> StudentNum;
	for (int i = 0; i < StudentNum; i++)
	{
		std::cin >> Student.ID >> Student.Study >> Student.Quality;
		Student.Sum = (double)Student.Study * 0.7 + (double)Student.Quality * 0.3;
		if (IsExcellent())
			std::cout << "Excellent\n";
		else
			std::cout << "Not excellent\n";
	}

	return 0;
}