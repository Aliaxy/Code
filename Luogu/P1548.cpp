#include <cstdio>

int main()
{
	int n, m, s1 = 0, s2;
	scanf("%d %d", &n, &m);

	s2 = ((m + 1) * (n + 1) * m * n) / 4;
	for (; m > 0 && n > 0; m--, n--)
		s1 += m * n;

	printf("%d %d\n", s1, s2 - s1);

	return 0;
}