#include <iostream>
#include <string>
#include <algorithm>

const int MAX = 4e4 + 1;

std::string a, b;
int Num[MAX];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> a >> b;
	std::reverse(a.begin(), a.end());
	std::reverse(b.begin(), b.end());
	if (a.size() < b.size())
	{
		std::string temp = a;
		a = b;
		b = temp;
	}
	int lena = a.size(), lenb = b.size();
	for (int i = 0; i < lena; i++)
		for (int j = 0; j < lenb; j++)
			Num[i + j] += (a[i] - '0') * (b[j] - '0');
	for (int i = 0; i < lena + lenb; i++)
	{
		if (Num[i] > 9)
		{
			Num[i + 1] += Num[i] / 10;
			Num[i] %= 10;
		}
	}
	std::reverse(Num, Num + lena + lenb);
	int cnt = 0;
	for (int i = 0; !Num[i] && i < 5; i++)
		cnt++;
	if (Num[cnt] == 0)
	{
		std::cout << "0\n";
	}
	else
		for (int i = cnt; i < lena + lenb; i++)
			std::cout << Num[i];

	return 0;
}