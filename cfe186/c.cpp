#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    for(int i = 1; i <= n; i ++ ) cin >> b[i];
    for(int i = 1; i <= n; i ++ ) cin >> c[i];
    int res1 = 0, res2 = 0;
    for(int i = 1; i <= n; i ++ )
    {
        int flag = 0;
        for(int j = 1; j <= n; j ++ )
        {
            if(a[j] >= b[(j + i) % n + 1])
            {
                flag = 1;
            }
        }
        res1 += (flag == 0);
        flag = 0;
        for(int j = 1; j <= n; j ++ )
        {
            if(b[j] >= c[(j + i) % n + 1])
            {
                flag = 1;
            }
        }
        res2 += (flag == 0);
    }
    cout << res1 * res2 * n << endl;
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
}