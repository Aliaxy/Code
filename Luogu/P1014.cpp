#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int num,
		sum = 0,
		i = 0,
		differ;

	cin >> num;

	while (sum < num)
	{
		i++;
		sum = i * (i + 1) / 2;
	}

	differ = sum - num;

	if (i % 2 == 0)
	{
		printf("%d/%d\n", i - differ, differ + 1);
	}
	else
	{
		printf("%d/%d\n", differ + 1, i - differ);
	}

	return 0;
}