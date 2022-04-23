#include <iostream>
#include <string>
#include <cctype>

std::string Target, Find;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::getline(std::cin, Target);
	std::getline(std::cin, Find);
	for (int i = 0; i < Target.length(); i++)
		Target[i] = std::tolower(Target[i]);
	Target = ' ' + Target + ' ';
	for (int i = 0; i < Find.length(); i++)
		Find[i] = std::tolower(Find[i]);
	Find = ' ' + Find + ' ';
	if (Find.find(Target) == -1)
		std::cout << "-1\n";
	else
	{
		int FirstPos = Find.find(Target), Cnt = 0;
		int flag = Find.find(Target);
		while (flag != -1)
		{
			Cnt++;
			flag = Find.find(Target, flag + 1);
		}
		std::cout << Cnt << ' ' << FirstPos << '\n';
	}

	return 0;
}