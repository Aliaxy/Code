#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	int cnt[26] = {0},
		MaxCnt = 0;
	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
		cnt[s[i] - 'a']++;

	for (int i = 0; i < 26; i++)
		MaxCnt = max(MaxCnt, cnt[i]);

	cout << MaxCnt << endl;

	return 0;
}