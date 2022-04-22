#include <iostream>
#include <cmath>
using namespace std;

double dis(int, int, int, int);

int main()
{
	int n, x1, x2, y1, y2, sum = 0;
	int r[50][3];
	double r1 = 0, r2 = 0;
	cin >> n;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> r[j][i];
	}
	cin >> x1 >> y1 >> x2 >> y2;
	for (int i = 0; i < n; i++)
	{
		r1 = dis(x1, y1, r[i][0], r[i][1]);
		r2 = dis(x2, y2, r[i][0], r[i][1]);
		if ((r1 < r[i][2] && r2 > r[i][2]) || (r2 < r[i][2] && r1 > r[i][2]))
			sum++;
	}

	cout << sum << endl;

	return 0;
}

double dis(int x1, int y1, int x2, int y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}