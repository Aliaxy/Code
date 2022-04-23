#include <iostream>
#include <string>

std::string Target;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int len, Cnt = 0;
	std::cin >> len >> Target;
	int temp = Target.find("VK");
	while (temp != -1)
	{
		Cnt++;
		Target = Target.erase(temp, 2);
		Target = Target.insert(temp, "X");
		temp = Target.find("VK");
	}
	len = Target.size();
	for (int i = 0; i < len - 1; i++)
		if (Target[i] == Target[i + 1] && Target[i] != 'X')
		{
			Cnt++;
			break;
		}

	std::cout << Cnt << '\n';

	return 0;
}