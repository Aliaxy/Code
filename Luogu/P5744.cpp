#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::string s;
		int a, b;
		std::cin >> s >> a >> b;
		b = b / 5 * 6;
		b = b > 600 ? 600 : b;
		std::cout << s << ' ' << a + 1 << ' ' << b << '\n';
	}

	return 0;
}