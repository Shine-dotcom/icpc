#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    int ans = 0, cnt = 0;
    vector<int> res;
    for(int i = 1, j = n; i <= j; j -- )
    {
        while(i < j && cnt + a[j] < x)
        {
            cnt += a[i];
            res.push_back(a[i]);
            i ++ ;
        }
        if(cnt + a[j] >= x)
        {
            ans += a[j];
            cnt = (cnt + a[j]) % x;
        }
        res.push_back(a[j]);
    }
    cout << ans << endl;
    for(auto x : res)
    {
        cout << x << ' ';
    }
    cout << endl;
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