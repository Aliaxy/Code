#include <iostream>
#include <cstring>

int Height, Width;
int Matrix[81];
__int128_t Dp[81][81],
	P[81];

__int128_t dp(int l, int r)
{
	if (Dp[l][r] != -1)
		return Dp[l][r];
	if (r - l >= 1)
		Dp[l][r] = std::max(Matrix[l] * P[Width - (r - l)] + dp(l + 1, r), Matrix[r] * P[Width - (r - l)] + dp(l, r - 1));
	else
		Dp[l][r] = Matrix[l] * P[Width - (r - l)];
	return Dp[l][r];
}

void print(__int128_t x)
{
	if (!x)
		return;
	if (x)
		print(x / 10);
	putchar(x % 10 + '0');
}

int main()
{
	std::ios::sync_with_stdio(false);
	__int128_t ans = 0;
	std::cin >> Height >> Width;
	P[0] = 1;
	for (int i = 1; i <= Width; i++)
		P[i] = P[i - 1] * 2;
	for (int i = 0; i < Height; i++)
	{
		for (int j = 1; j <= Width; j++)
			std::cin >> Matrix[j];
		memset(Dp, -1, sizeof(Dp));
		ans += dp(1, Width);
	}
	if (ans)
		print(ans);
	else
		std::cout << "0\n";

	return 0;
}