#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    string s;
    cin >> s;
    vector<int> a;
    for(auto x : s)
    {
        a.push_back(x - 'A');
    }
    int cnt[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    int ans = 0;
    for(int i = 0; i <= 25; i ++ )
    {
        int tmp = 0;
        for(int j = 0; j < a.size(); j ++ )
        {
            tmp += cnt[(a[j] + i) % 26];
        }
        ans = max(ans, tmp);
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
    return 0;
}