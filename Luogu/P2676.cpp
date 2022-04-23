#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int CowNum, ShelfHeight, sum = 0, count = 0;
	cin >> CowNum >> ShelfHeight;
	int *CowHegiht = (int *)malloc(sizeof(int) * CowNum);

	for (int i = 0; i < CowNum; i++)
	{
		cin >> CowHegiht[i];
	}

	sort(CowHegiht, CowHegiht + CowNum, cmp);

	while (sum < ShelfHeight)
	{
		sum += CowHegiht[count];
		count++;
	}

	cout << count << endl;

	free(CowHegiht);

	return 0;
}