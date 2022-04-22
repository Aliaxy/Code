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
// #include <queue>
// #include <deque>
// #include <functional>
// #include <bitset>

const int MAX = 1e6 + 1;
struct node
{
    int left, right;
} tree[MAX];

int f[MAX], ans = 1;
;

int DFS(int x, int depth)
{
    if (f[x]) return f[x];
    if (!x) return 0;
    if (tree[x].left || tree[x].right)
        f[x] = std::max(DFS(tree[x].left, depth + 1), DFS(tree[x].right, depth + 1));
    max(ans, depth);
    return depth;
}


int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr), std::cout.tie(nullptr);

    int n = read();
    for (int i = 1; i <= n; i++)
        tree[i].left = read(), tree[i].right = read();
    for (int i = 1; i <= n; i++) DFS(i, 1);
    write(ans);

    return 0;
}