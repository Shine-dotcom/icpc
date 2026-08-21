#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    int ans = 0;
    for(int i = n - 1; i >= 1; i -- )
    {
        while(a[i + 1] < a[i] && a[i] >= 10)
        {
            int sum = 0;
            while(a[i])
            {
                sum += a[i] % 10;
                a[i] /= 10;
            }
            a[i] = sum;
            ans ++;
        }
        if(a[i] > a[i + 1])
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
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