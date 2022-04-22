#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char s[255];
	int a[3] = {0};
	cin >> s;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == '=')
			if (s[i + 1] >= '0' && s[i + 1] <= '9')
				a[s[i - 2] - 'a'] = s[i + 1] - '0';
			else
				a[s[i - 2] - 'a'] = a[s[i + 1] - 'a'];
	}
	cout << a[0] << " " << a[1] << " " << a[2] << endl;
	return 0;
}