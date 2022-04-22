#include <iostream>
#include <string>

std::string str;

int main()
{

	int TestCase = 0, flag;
	std::cin >> TestCase;
	std::getchar();
	std::getchar();

	while (TestCase--)
	{
		std::getline(std::cin, str);
		int len = str.size() - 1, i = 0;
		if (str[0] == 'a')
			flag = 1, i += 2;
		else if (str[0] == 'b')
			flag = 2, i += 2;
		else if (str[0] == 'c')
			flag = 3, i += 2;
		std::string str2 = "\0";
		int num1 = 0, num2 = 0, p = 0;
		for (; i < len; i++)
		{
			if (str[i] != ' ')
			{
				str2 += str[i];
				if (p)
					num2 = num2 * 10 + (str[i] - '0');
				else
					num1 = num1 * 10 + (str[i] - '0');
			}
			else
			{
				p = 1;
				if (flag == 1)
					str2 += '+';
				else if (flag == 2)
					str2 += '-';
				else
					str2 += '*';
			}
		}
		str2 += '=';
		if (flag == 1)
		{
			num1 += num2;
			str2 += std::to_string(num1);
		}
		else if (flag == 2)
		{
			num1 -= num2;

			str2 += std::to_string(num1);
		}
		else
		{
			num1 *= num2;
			str2 += std::to_string(num1);
		}
		std::cout << str2 << '\n';
		std::cout << str2.length() << '\n';
	}

	return 0;
}