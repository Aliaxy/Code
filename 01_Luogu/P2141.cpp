#include <iostream>
#include <set>

const int MAX = 2e5;

int Num[100], Visit[MAX];
std::set<int> st;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> Num[i];
		st.insert(Num[i]);
	}
	int cnt = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (!Visit[Num[i] + Num[j]] && st.count(Num[i] + Num[j]))
			{
				cnt++;
				Visit[Num[i] + Num[j]] = 1;
			}
		}

	std::cout << cnt << '\n';

	return 0;
}