#include <iostream>
#include <cstdio>

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr);
	double ColaSum, StuNum;
	std::cin >> ColaSum >> StuNum;
	printf("%.3f\n%d\n", ColaSum / StuNum, (int)StuNum * 2);

	return 0;
}