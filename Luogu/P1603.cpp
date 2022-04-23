#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>

std::map<std::string, int> Match;
std::string str;
int f[100];

int main()
{
	Match["a"] = Match["one"] = Match["another"] = Match["first"] = 1,
	Match["two"] = Match["both"] = Match["second"] = 2,
	Match["three"] = Match["third"] = 3, Match["four"] = 4, Match["five"] = 5,
	Match["six"] = 6, Match["seven"] = 7, Match["eight"] = 8, Match["nine"] = 9,
	Match["ten"] = 10, Match["eleven"] = 11, Match["twelve"] = 12, Match["thirteen"] = 13,
	Match["fourteen"] = 14, Match["fifteen"] = 15, Match["sixteen"] = 16,
	Match["seventeen"] = 17, Match["eighteen"] = 18, Match["nineteen"] = 19, Match["twenty"] = 20;

	int Cnt = 0;
	for (int i = 0; i < 6; i++)
	{
		std::cin >> str;
		if (Match[str])
		{
			int temp = Match[str] * Match[str] % 100;
			if (temp)
				f[Cnt++] = temp;
		}
	}
	std::cin >> str;
	std::sort(f, f + Cnt);
	std::cout << f[0];
	for (int i = 1; i < Cnt; i++)
		printf("%.2d", f[i]);

	std::cout << '\n';
	return 0;
}