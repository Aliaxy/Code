#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	if (n <= 150)
		printf("%.1f\n", n * 0.4463);
	else if (n > 150 && n < 401)
		printf("%.1f\n", (n - 150) * 0.4663 + 66.945);
	else
		printf("%.1f\n", (n - 400) * 0.5663 + 183.52);

	return 0;
}