#include <cstdio>

int main()
{
	int a, b, c, d;
	char ch;
	scanf("%d %c %d %d %c %d", &a, &ch, &b, &c, &ch, &d);

	a *= c;
	b *= d;
	c = a;
	d = b;
	while (c != d)
	{
		if (c > d)
			c -= d;
		else
			d -= c;
	}
	a /= d;
	b /= d;
	printf("%d %d\n", b, a);

	return 0;
}