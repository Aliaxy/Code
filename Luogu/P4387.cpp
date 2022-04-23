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
#include <stack>
// #include <map>
// #include <unordered_map>
// #include <set>
// #include <queue>
// #include <deque>
// #include <functional>
// #include <bitset>

const int MAX = 1e5;

int a[MAX], b[MAX];

std::stack<int> st;

int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t = read();
    while (t--)
    {
        int n = read();
        for (int i = 0; i < n; i++) a[i] = read();
        for (int i = 0; i < n; i++) b[i] = read();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            st.push(a[i]);
            while (st.top() == b[j])
            {
                st.pop();
                j++;
                if (st.empty()) break;
            }
        }
        std::cout << (st.empty() ? "Yes" : "No") << '\n';
        while (!st.empty()) st.pop();
    }

    return 0;
}