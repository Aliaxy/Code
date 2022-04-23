#include <iostream>
using namespace std;

int main()
{
	int n, m,
		a[3000],
		ans, sum = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		ans = i <= m - 1 ? sum += a[i] : min(ans, sum += a[i] - a[i - m]);
	}

	cout << ans << endl;

	return 0;
}