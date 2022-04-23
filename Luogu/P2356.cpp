#include <iostream>
#include <algorithm>
using namespace std;

int SumRowCol(int **a, int x, int y, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[x][i] + a[i][y];
	}

	return sum;
}

int main()
{
	int n, MaxSocre = 0;
	int **Enemy;
	bool flag = false;
	cin >> n;
	Enemy = (int **)malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++)
	{
		Enemy[i] = (int *)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++)
			cin >> Enemy[i][j];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!Enemy[i][j])
			{
				flag = true;
				MaxSocre = max(MaxSocre, SumRowCol(Enemy, i, j, n));
			}
		}
	}
	if (flag)
		cout << MaxSocre << endl;
	else
		cout << "Bad Game!\n";
	for (int i = 0; i < n; i++)
		free(Enemy[i]);
	free(Enemy);

	return 0;
}