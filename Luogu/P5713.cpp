#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int TopicNum;
	std::cin >> TopicNum;
	std::string p = (TopicNum * 2 < 11) ? "Local\n" : "Luogu\n";
	std::cout << p;

	return 0;
}