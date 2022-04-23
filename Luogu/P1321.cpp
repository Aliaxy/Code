#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
	char ch[256];
	int boy = 0,
		girl = 0;
	scanf("%s", ch);
	for (int i = 0; i < strlen(ch) - 2; i++)
		if (ch[i] == 'b' || ch[i + 1] == 'o' || ch[i + 2] == 'y')
			boy++;
	for (int i = 0; i < strlen(ch) - 3; i++)
		if (ch[i] == 'g' || ch[i + 1] == 'i' || ch[i + 2] == 'r' || ch[i + 3] == 'l')
			girl++;
	printf("%d\n%d\n", boy, girl);
	return 0;
}