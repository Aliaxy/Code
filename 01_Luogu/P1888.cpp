#include <iostream>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int a, b, c;
	std::cin >> a >> b >> c;
	int Max = std::max(a, std::max(b, c)),
		Min = std::min(a, std::min(b, c));
	int x = std::__gcd(Max, Min);
	Max /= x, Min /= x;
	std::cout << Min << '/' << Max << '\n';

	return 0;
}