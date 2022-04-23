#include <cstdio>

int main()
{
	float s, x, v = 7.0, sum = 0.0;
	scanf("%f %f", &s, &x);

	while (sum < s - x)
	{
		sum += v;
		v *= 0.98;
	}

	if (sum + v * 0.98 > s + x)
		printf("n");
	else
		printf("y");

	return 0;
}