#include <iostream>
#include <cstdio>
#include <cmath>

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr);
	double a, b, c;
	std::cin >> a >> b >> c;
	double p = 0.5 * (a + b + c);
	printf("%.1f\n", std::sqrt(p * (p - a) * (p - b) * (p - c)));
	return 0;
}