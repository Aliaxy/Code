#include <iostream>
using namespace std;

int main()
{
    int hight[10],
        max,
        num;

    for (int i = 0; i < 10; i++)
    {
        cin >> hight[i];
    }
    cin >> max;
    for (int i = 0; i < 10; i++)
    {
        if (hight[i] <= (max + 30))
            num++;
    }

    cout << num << endl;

    system("pause");

    return 0;
}