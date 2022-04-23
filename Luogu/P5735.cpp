#include <iostream>
#include <cmath>
#include <cstdio>

double Point[3][2];

double Dis(int i, int j)
{
	return std::sqrt(std::pow(Point[i][0] - Point[j][0], 2) + std::pow(Point[i][1] - Point[j][1], 2));
}

int main()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			std::cin >> Point[i][j];
	double Circum = 0.0;
	for (int i = 0; i < 2; i++)
		for (int j = i + 1; j < 3; j++)
			Circum += Dis(i, j);
	printf("%.2f\n", Circum);

	return 0;
}