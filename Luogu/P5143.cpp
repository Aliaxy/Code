#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>

struct Info
{
	double x, y, z;
	bool operator<(const Info &a) const
	{
		return z < a.z;
	}
};

std::vector<Info> Point;

double Dis(int i, int j)
{
	return std::sqrt(std::pow((Point[i].x - Point[j].x), 2) + std::pow((Point[i].y - Point[j].y), 2) + std::pow((Point[i].z - Point[j].z), 2));
}

int main()
{
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		double x, y, z;
		std::cin >> x >> y >> z;
		Point.push_back({x, y, z});
	}
	std::sort(Point.begin(), Point.end());
	double sum = 0.0;
	for (int i = 0; i < n - 1; i++)
		sum += Dis(i, i + 1);
	printf("%.3f\n", sum);

	return 0;
}