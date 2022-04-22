#include <iostream>
#include <cstdio>

void run(int x)
{
	int p = 1, cnt = -1;
	printf("2");
	while (x >= p)
	{
		cnt++;
		p *= 2;
	}
	if (cnt == 0 || cnt == 2)
		printf("(%d)", cnt);
	if (cnt >= 3)
	{
		printf("(");
		run(cnt);
		printf(")");
	}
	x -= p / 2;
	if (x)
	{
		printf("+");
		run(x);
	}
}
int main()
{
	int x;
	std::cin >> x;
	run(x);
}