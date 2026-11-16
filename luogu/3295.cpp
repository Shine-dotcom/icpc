#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e5 + 10;
int fa[N], f[N][20];
int f(int x)
{
    return fa[x] = (fa[x] == x ? x : f(fa[x]));
}
void u(int x, int y)
{
    x = f(x);
    y = f(y);
    if(x != y)
    {
        fa[x] = y;
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) fa[i] = i;
    while(m -- )
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        // ???不会写，cnm
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t -- ) solve();
    return 0;
}