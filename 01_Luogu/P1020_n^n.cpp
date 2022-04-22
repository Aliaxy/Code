#include <iostream>
#include <algorithm>

int MissileNum, MissileHeight[100000], Dp[100000], DpA[100000];

int main()
{
	std::ios::sync_with_stdio(false);
	while (std::cin >> MissileHeight[MissileNum])
	{
		Dp[MissileNum] = 1;
		DpA[MissileNum] = 1;
		MissileNum++;
	}
	int MaxSystem = 1, MaxMissile = 0;
	for (int i = 1; i < MissileNum; i++)
	{
		for (int j = 0; j < i; j++)
			if (MissileHeight[i] > MissileHeight[j])
			{
				Dp[i] = std::max(Dp[i], Dp[j] + 1);
			}
			else
			{
				DpA[i] = std::max(DpA[i], DpA[j] + 1);
			}
		MaxSystem = std::max(Dp[i], MaxSystem);
		MaxMissile = std::max(DpA[i], MaxMissile);
	}
	std::cout << MaxMissile << "\n"
			  << MaxSystem << "\n";

	return 0;
}