#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(105);
    for(auto &x : a) cin >> x, cnt[x] ++ ;
    int ans = 0;
    for(int i = 0; i <= 100; i ++ )
    {
        if(cnt[i] > 0)
        {
            ans ++;
            continue;
        }
        break;
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