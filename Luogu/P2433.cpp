#include <iostream>
#include <cstdio>
#include <cmath>

void Solve_1()
{
	std::cout << "I love Luogu!\n";
}

void Solve_2()
{
	std::cout << 6 << ' ' << 4 << '\n';
}

void Solve_3()
{
	std::cout << 3 << '\n';
	std::cout << 12 << '\n';
	std::cout << 2 << '\n';
}

void Solve_4()
{
	printf("%.3f\n", 500.0 / 3);
}

void Solve_5()
{
	std::cout << "15\n";
}

void Solve_6()
{
	std::cout << std::sqrt(36 + 81) << '\n';
}

void Solve_7()
{
	std::cout << "110\n"
			  << "90\n"
			  << "0\n";
}

void Solve_8()
{
	const double PI = 3.141593;
	int r = 5;
	std::cout << 2 * PI * r << '\n';
	std::cout << PI * r * r << '\n';
	std::cout << PI * r * r * r * 4 / 3 << '\n';
}

void Solve_9()
{
	std::cout << 22 << '\n';
}

void Solve_10()
{
	std::cout << 9 << '\n';
}

void Solve_11()
{
	std::cout << 100 / 3.0 << '\n';
}

void Solve_12()
{
	std::cout << (int)('M' - 'A') + 1 << '\n';
	std::cout << (char)('A' + 17) << '\n';
}

void Solve_13()
{
	const double PI = 3.141593;
	int r1 = 64, r2 = 1000;
	double V = PI * (r1 + r2) * 4 / 3;
	std::cout << (int)pow(V, 1.0 / 3) << '\n';
}

void Solve_14()
{
	std::cout << 50 << '\n';
}

int main()
{
	int Case;
	std::cin >> Case;
	switch (Case)
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
	case 4:
		Solve_4();
		break;
	case 5:
		Solve_5();
		break;
	case 6:
		Solve_6();
		break;
	case 7:
		Solve_7();
		break;
	case 8:
		Solve_8();
		break;
	case 9:
		Solve_9();
		break;
	case 10:
		Solve_10();
		break;
	case 11:
		Solve_11();
		break;
	case 12:
		Solve_12();
		break;
	case 13:
		Solve_13();
		break;
	default:
		Solve_14();
		break;
	}

	return 0;
}