#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(k + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    for(int i = 1; i <= k; i ++ )
    {
        cin >> b[i];
    }
    sort(a.begin() + 1, a.end(), [&](int x, int y){
        return x > y;
    });
    sort(b.begin(), b.end());
    // for(int i = 1; i <= k; i ++ )
    // {
    //     cout << b[i] << ' ';
    // }
    // cout << endl;
    for(int j = 0, i = 1; j < n && i <= k; i ++ )
    {
        while(j < n && b[i]){
            j ++;
            b[i] --;
        }
        if(b[i] == 0)
        a[j] = 0;
    }
    // for(int i = 1; i <= n; i ++ )
    // {
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    int res = 0;
    for(int i = 1; i <= n; i ++ )
    {
        res += a[i];
    }
    cout << res << endl;
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