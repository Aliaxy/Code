#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	int ans;
	string a;
	int num[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
	getline(cin, a);
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] >= 'a' && a[i] <= 'z')
			ans += num[a[i] - 'a'];
		if (a[i] == ' ')
			ans++;
	}
	printf("%d", ans);
	return 0;
}