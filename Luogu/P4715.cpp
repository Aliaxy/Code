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

// inline void max(int &a, int b) { a < b ? a = b : 0; }
// inline void min(int &a, int b) { a > b ? a = b : 0; }

// #include <vector>
// #include <stack>
// #include <map>
// #include <unordered_map>
// #include <set>
// #include <queue>
// #include <deque>
// #include <functional>
// #include <bitset>

const int MAX = 150;

struct node
{
    int data, ID;
} a[150], SegTree[MAX << 2];

inline node max(node x, node y) { return x.data > y.data ? x : y; }
inline node min(node x, node y) { return x.data < y.data ? x : y; }

void Build(int root, int l, int r)
{
    if (l == r)
    {
        SegTree[root] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    Build(root * 2, l, mid);
    Build(root * 2 + 1, mid + 1, r);
    SegTree[root] = max(SegTree[root << 1], SegTree[(root << 1) + 1]);
}


int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr), std::cout.tie(nullptr);

    int n = read();
    for (int i = 1; i <= (1 << n); i++)
        a[i].ID = i, a[i].data = read();
    Build(1, 1, 1 << n);
    write(min(SegTree[2], SegTree[3]).ID);


    return 0;
}