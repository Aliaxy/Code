#include <iostream>
using namespace std;

int main()
{
	char a[255];
	int count = 0,
		i = 0;
	bool flag;

	cin.getline(a, 255);

	while (a[i] != '@')
	{
		if (a[i] == '(')
			count++;
		if (a[i] == ')')
			count--;
		if (count < 0)
		{
			cout << "NO" << endl;
			break;
		}
		i++;
	}

	if (a[i] == '@')
	{
		if (!count)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}