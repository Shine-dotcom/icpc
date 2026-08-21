//中国剩余定理



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
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++ )
    {
        cin >> b[i];
    }
    for(int i = 1; i <= n; i ++ )
    {
        a[i] = ((a[i] % b[i]) + b[i]) % b[i];
    } 
    int a1 = a[1], m1 = b[1];
    for(int i = 2; i <= n; i ++ )
    {
        int a2 = a[i], m2 = b[i];
        int k1, k2;
        int d = exgcd(m1, m2, k1, k2);
        k1 *= (a2 - a1) / d;
        int t = m2 / d;
        k1 = ((k1 % t) + t) % t;
        a1 = k1 * m1 + a1;
        m1 = m1 * m2 / d;
    }
    cout << a1 << endl;
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