#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> idx(1);
    for(int i = 1; i <= n; i ++ )
    {
        if(s[i] == '1')
        {
            idx.push_back(i);
        }
    }
    // for(auto x : idx)
    // {
    //     cout << x << ' ';
    // }
    // cout << endl;
    int ls = idx.size() - 1;
    int ans = 0;
    for(int i = 1; i <= ls; i ++ )
    {
        ans = (ans + (2 * i - 1 - ls) * idx[i]) % mod;
    }
    cout << ans << endl;
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