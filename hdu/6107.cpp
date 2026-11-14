#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e5 + 10;
int a[N], f1[N][30], f2[N][30], pre[N], w, pw, dw, n;
int fit(int i, int width)
{
    if(i > n) return 0;
    if(a[i] > width) return 0;
    int lo = i, hi = n;
    while(lo < hi)
    {
        int mid = (lo + hi + 1) >> 1;
        int cost = (pre[mid] - pre[i - 1]) + (mid - i);
        if(cost <= width) lo = mid;
        else hi = mid - 1;
    }
    return lo - i + 1;
}
void ST()
{
    for(int i = 1; i <= n; i ++ ) f1[i][0] = f2[i][0] = 0;
    f1[n + 1][0] = f2[n + 1][0] = 0;
    for(int i = 1, j = 1; i <= n + 1; i ++ )
    {
        if(i > n) continue;
        int lc = fit(i, dw);
        f1[i][0] = lc + fit(i + lc, w - pw - dw);
        f2[i][0] = fit(i, w);
    }
    int k = 20;
    for(int i = 1; i <= k; i ++ )
    {
        for(int j = 1; j <= n; j ++ )
        {
            int m = j + f1[j][i - 1];
            f1[j][i] = f1[j][i - 1] + (m <= n ? f1[m][i - 1] : 0);
        }
    }
    for(int i = 1; i <= k; i ++ )
    {
        for(int j = 1; j <= n; j ++ )
        {
            int m = j + f2[j][i - 1];
            f2[j][i] = f2[j][i - 1] + (m <= n ? f2[m][i - 1] : 0);
        }
    }
}
int resolve1(int i, int x)
{
    int j = 0;
    while(i <= n && x)
    {
        if(i <= n && (x & 1)) i += f1[i][j];
        j ++;
        x >>= 1;
    }
    return i;
}
int resolve2(int i)
{
    int h = 0;
    while(i <= n)
    {
        int j = 0;
        while(i + f2[i][j + 1] <= n) j ++;
        i += f2[i][j];
        h += (1 << j);
    }
    return h;
}
int resolve3(int i, int x)
{
    if(x == 0) return i;
    int j = 0;
    while(i <= n && x)
    {
        if(i <= n && (x & 1)) i += f2[i][j];
        j ++;
        x >>= 1;
    }
    return i;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t -- )
    {
        cin >> n >> w >> pw >> dw;
        for(int i = 1; i <= n; i ++ ) cin >> a[i], pre[i] = pre[i - 1] + a[i];
        a[n + 1] = w + 1;
        ST();
        int q;
        cin >> q;
        while(q -- )
        {
            int x, h;
            cin >> x >> h;
            int need = resolve2(1);
            if(need < x)
            {
                cout << need + h << endl;
                continue;
            }
            int st1 = resolve3(1, min(x - 1, n));
            int st2 = resolve1(st1, min(h, n));
            cout << (x - 1) + h + resolve2(st2) << endl;
        }
    }
    return 0;
}

// 有问题的代码，待调试
// created at 2026/11/14 10:43