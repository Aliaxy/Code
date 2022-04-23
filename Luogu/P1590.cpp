#include <iostream>
#include <cstdio>
using namespace std;

int T;
std ::string s;
int main()
{
	std ::scanf("%d", &T);
	while (T--)
	{
		std ::cin >> s;
		//льеп©╙й╪
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == '7')
			{
				s[i] = '6';
				for (int j = i + 1; j < s.length(); ++j)
					s[j] = '9';
				break;
			}
		}

		int ans = 0;
		for (int i = s.length() - 1, atr = 1; i >= 0; --i, atr *= 9)
			ans += atr * (s[i] - '0') - (s[i] - '0' > 7 ? atr : 0);
		std ::printf("%d\n", ans);
	}
	return 0;
}