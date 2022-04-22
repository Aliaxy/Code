#include <iostream>
using namespace std;

int main()
{
	int n, i;
	char x[101], z[101];
	cin >> n >> x >> z;

	for (i = 0; i < n; i++)
	{
		if (x[i] < z[i])
		{
			cout << -1 << endl;
			break;
		}
	}
	if (i == n)
		cout << z << endl;

	return 0;
}