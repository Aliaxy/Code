#include <iostream>
#include <string>

const int MOVE[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

std::string Map[10];
int JohnX, JohnY, JohnFace, CowX, CowY, CowFace;
int Vis[10][10][10][10];

bool Judge(int x, int y)
{
	if (x < 0 || y < 0 || x > 9 || y > 9)
		return false;
	if (Map[x][y] == '*')
		return false;
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	for (int i = 0; i < 10; i++)
	{
		std::cin >> Map[i];
		if (Map[i].find('F') != -1)
		{
			JohnX = i;
			JohnY = Map[i].find('F');
		}
		if (Map[i].find('C') != -1)
		{
			CowX = i;
			CowY = Map[i].find('C');
		}
	}
	int Time = 0;
	while (CowX != JohnX || CowY != JohnY)
	{
		if (Vis[CowX][CowY][JohnX][JohnY]++ == 4)
		{
			Time = 0;
			break;
		}
		if (!Judge(CowX + MOVE[CowFace][0], CowY + MOVE[CowFace][1]))
			CowFace = (CowFace + 1) % 4;
		else
			CowX += MOVE[CowFace][0], CowY += MOVE[CowFace][1];
		if (!Judge(JohnX + MOVE[JohnFace][0], JohnY + MOVE[JohnFace][1]))
			JohnFace = (JohnFace + 1) % 4;
		else
			JohnX += MOVE[JohnFace][0], JohnY += MOVE[JohnFace][1];
		Time++;
	}
	std::cout << Time << '\n';

	return 0;
}