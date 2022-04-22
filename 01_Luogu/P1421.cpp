#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int m,
		n;
	scanf("%d %d", &m, &n);
	int sum = 10 * m + n;

	printf("%d\n", int(sum / 19));

	return 0;
}