#include <iostream>

const int MAX = 200;
const int Score[5][5] = {
	{0, 0, 1, 1, 0},
	{1, 0, 0, 1, 0},
	{0, 1, 0, 0, 1},
	{0, 0, 1, 0, 1},
	{1, 1, 0, 0, 0}};

int A[MAX], B[MAX];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int RoundNum, CycleA, CycleB;
	std::cin >> RoundNum >> CycleA >> CycleB;
	for (int i = 0; i < CycleA; i++)
		std::cin >> A[i];
	for (int i = 0; i < CycleB; i++)
		std::cin >> B[i];
	int WinA = 0, WinB = 0;
	for (int i = 0; i < RoundNum; i++)
	{
		WinA += Score[A[i % CycleA]][B[i % CycleB]];
		WinB += Score[B[i % CycleB]][A[i % CycleA]];
	}
	std::cout << WinA << ' ' << WinB << '\n';

	return 0;
}