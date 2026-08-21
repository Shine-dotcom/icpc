#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end(), [&](int x, int y){
        return x > y;
    });
    int res = 0;
    for(int i = 1; i <= n; i ++ )
    {
        if(a[i] - i + 1 <= 0) break;
        res += a[i] - i + 1;
    }
    cout << res << endl;
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
