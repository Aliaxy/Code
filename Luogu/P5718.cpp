#include <iostream>
#include <set>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::set<int> st;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		std::cin >> num;
		st.insert(num);
	}
	std::set<int>::iterator it = st.begin();
	std::cout << *it << " ";

	return 0;
}