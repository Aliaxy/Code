#include <iostream>
#include <cmath>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	double Weight, Height;
	std::cin >> Weight >> Height;
	double BMI = Weight / std::pow(Height, 2);
	if (BMI < 18.5)
		std::cout << "Underweight\n";
	else if (BMI >= 24)
	{
		std::cout << BMI << '\n';
		std::cout << "Overweight\n";
	}
	else
		std::cout << "Normal\n";

	return 0;
}