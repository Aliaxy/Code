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

const int MAX = 1e6 + 10, INF = 0x7fffffff;

struct node
{
    int val, siz, cnt, ls, rs;
} tree[MAX];

int tot;

inline void Add(int x, int val)
{
    tree[x].siz++;
    if (tree[x].val == val)
    {
        tree[x].cnt++;
        return;
    }
    if (tree[x].val > val)
    {
        if (tree[x].ls)
            Add(tree[x].ls, val);
        else
        {
            tree[++tot].val = val;
            tree[tot].siz = tree[tot].cnt = 1;
            tree[x].ls = tot;
        }
    }
    else
    {
        if (tree[x].rs)
            Add(tree[x].rs, val);
        else
        {
            tree[++tot].val = val;
            tree[tot].siz = tree[tot].cnt = 1;
            tree[x].rs = tot;
        }
    }
}

int QueryForward(int x, int val, int ans)
{
    if (tree[x].val >= val)
    {
        if (!tree[x].ls)
            return ans;
        else
            return QueryForward(tree[x].ls, val, ans);
    }
    else
    {
        if (!tree[x].rs) return (tree[x].val < val) ? tree[x].val : ans;
        if (tree[x].cnt)
            return QueryForward(tree[x].rs, val, tree[x].val);
        else
            return QueryForward(tree[x].rs, val, ans);
    }
}

int QueryBackward(int x, int val, int ans)
{
    if (tree[x].val <= val)
    {
        if (tree[x].rs == 0)
            return ans;
        else
            return QueryBackward(tree[x].rs, val, ans);
    }
    else
    {
        if (tree[x].ls == 0)
            return (tree[x].val > val) ? tree[x].val : ans;
        if (tree[x].cnt != 0)
            return QueryBackward(tree[x].ls, val, tree[x].val);
        else
            return QueryBackward(tree[x].ls, val, ans);
    }
}

int QueryVal(int x, int val)
{
    if (!x) return 0;
    if (val == tree[x].val) return tree[tree[x].ls].siz;
    if (val < tree[x].val) return QueryVal(tree[x].ls, val);
    return QueryVal(tree[x].rs, val) + tree[tree[x].ls].siz + tree[x].cnt;
}

int QueryRank(int x, int rk)
{
    if (x == 0) return INF;
    if (tree[tree[x].ls].siz >= rk)
        return QueryRank(tree[x].ls, rk);
    if (tree[tree[x].ls].siz + tree[x].cnt >= rk)
        return tree[x].val;
    return QueryRank(tree[x].rs, rk - tree[tree[x].ls].siz - tree[x].cnt);
}
int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr), std::cout.tie(nullptr);

    int n = read();
    while (n--)
    {
        int x = read(), y = read();
        switch (x)
        {
        case 1: write(QueryVal(1, y) + 1), putchar('\n'); break;
        case 2: write(QueryRank(1, y)), putchar('\n'); break;
        case 3: write(QueryForward(1, y, -INF)), putchar('\n'); break;
        case 4: write(QueryBackward(1, y, INF)), putchar('\n'); break;
        default:
        {
            if (!tot)
            {
                tot++;
                tree[tot].cnt = tree[tot].siz = 1;
                tree[tot].val = y;
            }
            else
                Add(1, y);
        }
        }
    }


    return 0;
}