#include <iostream>
#include <cmath>
using namespace std;

int Award(int);

int main()
{
	int n, num,
		sum = 0,
		DayContinu = 0,
		DayAward = 1,
		temp = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num)
		{
			if (temp)
			{
				DayContinu -= (int)pow(2, temp - 1);
				if (DayContinu < 0)
					DayContinu = 0;
				temp = 0;
			}
			DayContinu++;
			DayAward = Award(DayContinu);
			sum += DayAward;
		}
		else
		{
			temp++;
		}
	}

	cout << sum << endl;

	return 0;
}

int Award(int num)
{
	if (num < 3)
		return 1;
	if (num > 2 && num < 7)
		return 2;
	if (num > 6 && num < 30)
		return 3;
	if (num > 29 && num < 120)
		return 4;
	if (num > 119 && num < 365)
		return 5;
	if (num > 364)
		return 6;
}