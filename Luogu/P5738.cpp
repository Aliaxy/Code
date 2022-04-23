#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

int StuNum, JudgeNum;
std::vector<int> Score;

double FinalScore()
{
	std::sort(Score.begin(), Score.end());
	int ScoreSum = 0;
	for (int i = 1; i < JudgeNum - 1; i++)
		ScoreSum += Score[i];
	return (double)ScoreSum / (JudgeNum - 2);
}

int main()
{
	std::cin >> StuNum >> JudgeNum;
	double MaxScore = 0.0;
	for (int i = 0; i < StuNum; i++)
	{
		Score.clear();
		for (int j = 0; j < JudgeNum; j++)
		{
			int x;
			std::cin >> x;
			Score.push_back(x);
		}
		MaxScore = std::max(MaxScore, FinalScore());
	}
	printf("%.2f\n", MaxScore);

	return 0;
}