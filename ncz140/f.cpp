#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int exgcd(int a, int b, int &x, int &y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int gcd = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return gcd;
}
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    int a, b;
    int d = exgcd(x, y, a, b);
    int k1 = a / (y / d);
    int k2 = b / (x / d);
    int a1 = a - k1 * (y / d);
    int b1 = b + k1 * (x / d);
    int a2 = a + k2 * (y / d);
    int b2 = b - k2 * (x / d);
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> p[i];
    }
    if(x == 1 || y == 1)
    {
        cout << "Yes" << endl;
        return;
    }
    for(int i = 1; i <= n; i ++ )
    {
        if((p[i] - i) % d)
        {
            cout << "No" << endl;
            return;
        }
        if(a1 * x * abs(p[i] - i) / d >= n || b1 * y * abs(p[i] - i) / d >= n)
        {
            if(b2 * y * abs(p[i] - i) / d >= n || a2 * x * abs(p[i] - i) / d >= n)
            {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t -- )
    {
        solve();
    }
    return 0;
}