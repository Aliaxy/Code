#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> Node;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int num;
	std::cin >> num;
	Node.push_back(num);
	while (num != 1)
	{
		if (num & 1)
			Node.push_back(num = num * 3 + 1);
		else
			Node.push_back(num = num / 2);
	}
	std::reverse(Node.begin(), Node.end());
	int len = Node.size();
	for (int i = 0; i < len; i++)
		std::cout << Node[i] << ' ';

	return 0;
}