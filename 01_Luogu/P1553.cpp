#include <iostream>
#include <string>
#include <algorithm>

std::string Target;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> Target;
	int len = Target.size(),
		temp1 = Target.find('.'),
		temp2 = Target.find('/');

	if (temp1 != -1 || temp2 != -1)
	{
		int flag = 0;
		if (temp2 != -1)
			temp1 = temp2, flag = 1;
		std::reverse(Target.begin(), Target.begin() + temp1);
		std::reverse(Target.begin() + temp1 + 1, Target.end());
		if (flag)
			while (Target[temp1 + 1] == '0')
				Target.erase(temp1 + 1, 1);
		int a = Target.size();
		while (Target[a - 1] == '0')
		{
			Target.erase(a - 1, 1);
			a--;
		}
		if (Target[a - 1] == '.')
			Target.insert(Target.end(), '0');
	}
	else
	{
		if (Target[len - 1] == '%')
		{
			Target.erase(len - 1, 1);
			Target.insert(Target.begin(), '%');
		}
		std::reverse(Target.begin(), Target.end());
	}
	while (Target[0] == '0')
		Target.erase(0, 1);
	if (Target.size() == 0 || Target[0] == '.' || Target[0] == '/' || Target[0] == '%')
		Target.insert(Target.begin(), '0');
	std::cout << Target << '\n';

	return 0;
}