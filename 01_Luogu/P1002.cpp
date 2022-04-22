#include <iostream>

int Move[8][2] = {-2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1};
long long Dp[21];
bool Map[21][21];

int main()
{
    std::ios::sync_with_stdio(false);
    int EndX, EndY, HorseX, HorseY;
    std::cin >> EndX >> EndY >> HorseX >> HorseY;
    Map[HorseX][HorseY] = 1;
    for (int i = 0; i < 8; i++)
    {
        int TempX = HorseX + Move[i][0],
            TempY = HorseY + Move[i][1];
        if (TempX >= 0 && TempX <= EndX && TempY >= 0 && TempY <= EndY)
            Map[TempX][TempY] = 1;
    }
    Dp[0] = 1;
    for (int i = 0; i <= EndX; i++)
        for (int j = 0; j <= EndY; j++)
        {
            if (Map[i][j])
            {
                Dp[j] = 0;
                continue;
            }
            if (j != 0)
                Dp[j] += Dp[j - 1];
        }

    std::cout << Dp[EndY] << "\n";

    return 0;
}