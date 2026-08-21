#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> flag(26);
    for(int i = 0; i < n; i ++ )
    {
        flag[s[i] - 'a'] ^= 1;
    }
    int mn = -1, ans = 0;
    for(int i = 0; i < 26; i ++ )
    {
        if(flag[i] && mn == -1)
        {
            mn = i;
            continue;
        }
        if(flag[i] && mn != -1)
        {
            ans += i - mn;
            mn = -1;
        }
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