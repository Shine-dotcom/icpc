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
    s = " " + s;
    vector<int> a0;
    for(int i = 1, j = 1; i <= n; i ++ )
    {
        while(j < n && s[j + 1] == '0' && s[i] == '0') j++;
        if(s[j] == '0') a0.push_back(j - i + 1);
        // cout << i << ' ' << j << endl;
        i = j ++ ;
    }
    int m = a0.size();
    if(s[1] == '0' && s[n] == '0')
    {
        a0[0] += a0[m - 1];
        a0.pop_back();
    }
    int ans = 0;
    for(auto x : a0)
    {
        ans = max(ans, x);
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