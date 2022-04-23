#include <iostream>
#include <string>

std::string Initial, Target;

void Solve_1()
{
	std::cin >> Target;
	Initial += Target;
	std::cout << Initial << '\n';
}

void Solve_2()
{
	int a, b;
	std::cin >> a >> b;
	Initial = Initial.substr(a, b);
	std::cout << Initial << '\n';
}

void Solve_3()
{
	int Pos;
	std::cin >> Pos >> Target;
	Initial = Initial.insert(Pos, Target);
	std::cout << Initial << '\n';
}

void Solve_4()
{
	std::cin >> Target;
	int a = Initial.find(Target);
	std::cout << a << '\n';
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int OperateNum;
	std::cin >> OperateNum;
	std::cin >> Initial;
	while (OperateNum--)
	{
		int Kind;
		std::cin >> Kind;
		switch (Kind)
		{
		case 1:
			Solve_1();
			break;
		case 2:
			Solve_2();
			break;
		case 3:
			Solve_3();
			break;
		default:
			Solve_4();
			break;
		}
	}

	return 0;
}