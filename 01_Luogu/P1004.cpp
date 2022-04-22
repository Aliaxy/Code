#include <iostream>
#include <algorithm>

int Map[10][10],
    Dp[10][10][10][10];

int main()
{
    std::ios::sync_with_stdio(false);
    int MapSize;
    std::cin >> MapSize;
    int x, y, num;
    while (std::cin >> x >> y >> num, x || y || num)
        Map[x][y] = num;
    for (int i = 1; i <= MapSize; i++)
        for (int j = 1; j <= MapSize; j++)
            for (int k = 1; k <= MapSize; k++)
                for (int l = 1; l <= MapSize; l++)
                {
                    Dp[i][j][k][l] = std::max(std::max(Dp[i - 1][j][k - 1][l], Dp[i - 1][j][k][l - 1]), std::max(Dp[i][j - 1][k - 1][l], Dp[i][j - 1][k][l - 1])) + Map[i][j] + Map[k][l];
                    if (i == k && j == l)
                        Dp[i][j][k][l] -= Map[i][j];
                }
    std::cout << Dp[MapSize][MapSize][MapSize][MapSize] << "\n";

    return 0;
}