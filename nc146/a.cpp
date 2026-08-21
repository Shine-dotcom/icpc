#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i ++ )
    {
        int a;
        cin >> a;
        sum += a;
    }
    int cnt = sum - n;
    if(cnt <= n)
    {
        cout << cnt << endl;
        return;
    }
    if(sum % 2) cout << n - 1 << endl;
    else cout << n << endl;
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