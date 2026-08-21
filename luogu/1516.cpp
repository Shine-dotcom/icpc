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
    int x, y, m, n, L;
    cin >> x >> y >> m >> n >> L;
    int a, y0, d, s;
    if(m == n)
    {
        cout << "Impossible" << endl;
        return;
    }
    else if(m > n)
    {
        d = exgcd(m - n, L, a, y0);
        s = ((y - x) % L + L) % L;
        if(s % d)
        {
            cout << "Impossible" << endl;
            return;
        }
        a = a * s / d;
        int t = L / d;
        a = (a % t + t) % t;
    }
    else
    {
        d = exgcd(n - m, L, a, y0);
        s = ((x - y) % L + L) % L;
        if(s % d)
        {
            cout << "Impossible" << endl;
            return;
        }
        a = a * s / d;
        int t = L / d;
        a = (a % t + t) % t;
    }
    cout << a << endl;
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