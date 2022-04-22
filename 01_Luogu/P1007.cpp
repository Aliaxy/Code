#include <algorithm>
#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int BirdgeLength, SoldierNum, Position, MaxTime = 0, MinTime = 0;
	std::cin >> BirdgeLength >> SoldierNum;
	for (int i = 0; i < SoldierNum; i++)
	{
		std::cin >> Position;
		MaxTime = std::max(MaxTime, std::max(Position, BirdgeLength - Position + 1));
		MinTime = std::max(MinTime, std::min(Position, BirdgeLength - Position + 1));
	}
	std::cout << MinTime << " " << MaxTime << "\n";
	return 0;
}