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
#include <set>
// #include <queue>
// #include <deque>
// #include <functional>
// #include <bitset>

std::set<int> s;
std::set<int>::iterator k, a;

int ans;

int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr), std::cout.tie(nullptr);
    s.insert(192608170);
    s.insert(-192608170);
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        if (s.size() != 2)
        {
            k = s.lower_bound(x);
            if (*k != x)
            {
                a = k;
                a--;
                ans += std::min(abs(*a - x), abs(*k - x));
                s.insert(x);
            }
        }
        else
        {
            ans += x;
            s.insert(x);
        }
    }
    write(ans);

    return 0;
}