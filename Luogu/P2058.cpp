#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define debug(x, a) std::cout << #x << "==" << (x) << ((a) ? '\n' : ' ');

const double PI = acos(-1.0);

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

inline void write(int x)
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void max(int &a, int b) { a < b ? a = b : 0; }
inline void min(int &a, int b) { a > b ? a = b : 0; }

// #include <vector>
// #include <stack>
// #include <map>
// #include <unordered_map>
// #include <set>
#include <queue>
// #include <deque>
// #include <functional>
// #include <bitset>

int n, ans;

struct node
{
    int s, t;
};

std::queue<node> ship;

int nation[1000005];

int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr), std::cout.tie(nullptr);

    n = read();
    for (int i = 0; i < n; i++)
    {
        int t = read(), m = read();
        while (!ship.empty())
        {
            node now = ship.front();
            if (now.t + 86400 <= t)
            {
                nation[now.s]--;
                if (!nation[now.s]) ans--;
                ship.pop();
                continue;
            }
            break;
        }
        for (int j = 0; j < m; j++)
        {
            int x = read();
            node now = {x, t};
            ship.push(now);
            nation[x]++;
            if (nation[x] == 1) ans++;
        }
        write(ans), putchar('\n');
    }

    return 0;
}