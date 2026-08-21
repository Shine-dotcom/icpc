#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int exgcd(int a, int b, int &x, int &y)
{
    if(!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> c(n + 1), p(n + 1), l(n + 1);
    int mx = 0;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> c[i] >> p[i] >> l[i];
        mx = max(mx, c[i]);
    }
    auto check = [&](int m) -> bool
    {
        for(int i = 1; i <= n; i ++ )
        {
            for(int j = i + 1; j <= n; j ++ )
            {
                int x, y;
                int d = exgcd(p[j] - p[i], m, x, y);
                if((c[i] - c[j]) % d) continue;
                x *= (c[i] - c[j]) / d;
                int t = m / abs(d);
                x = (x % t + t) % t;
                if(abs(x) <= min(l[i], l[j])) return 0;
            }
        }
        return 1;
    };
    for(int i = mx; i <= 1e6; i ++ )
    if(check(i))
    {
        cout << i << endl;
        break;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t -- )
    {
        solve();
    }
}