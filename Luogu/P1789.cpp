#include <iostream>
using namespace std;

void Lighten(int Master[][100], int n, int x, int y, bool a)
{
	x--;
	y--;
	if (a)
	{
		for (int i = x - 2; i < n && i <= x + 2; i++)
		{
			if (i >= 0)
			{
				if (i == x - 2 || i == x + 2)
					Master[i][y] = 1;
				else if (i == x - 1 || i == x + 1)
					for (int j = y - 1; j < n && j <= y + 1; j++)
					{
						if (j >= 0)
							Master[i][j] = 1;
					}
				else
					for (int j = y - 2; j < n && j <= y + 2; j++)
					{
						if (j >= 0)
							Master[i][j] = 1;
					}
			}
		}
	}
	else
	{
		for (int i = x - 2; i < n && i <= x + 2; i++)
			if (i >= 0)
				for (int j = y - 2; j < n && j <= y + 2; j++)
					if (j >= 0)
						Master[i][j] = 1;
	}
}

int main()
{
	int n, TorchNum, FluoriteNum,
		x, y,
		Master[100][100] = {0},
		MasterSum = 0;
	cin >> n >> TorchNum >> FluoriteNum;

	for (int i = 0; i < TorchNum; i++)
	{
		cin >> x >> y;
		Lighten(Master, n, x, y, true);
	}

	for (int i = 0; i < FluoriteNum; i++)
	{
		cin >> x >> y;
		Lighten(Master, n, x, y, false);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			MasterSum += Master[i][j];

	cout << n * n - MasterSum << endl;

	return 0;
}