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
    vector<char> q;
    int ans = 0;
    for(int i = 1; i <= n; i ++ )
    {
        q.push_back(s[i]);
        if(q.size() >= 3 && q[q.size() - 1] == 'u' && q[q.size() - 2] == 'i' && q[q.size() - 3] == 'n')
        {
            ans += 3;
            for(int i = 1; i <= 3; i ++ )
            {
                q.pop_back();
            }
        }
        if(q.size() >= 2 && q[q.size() - 1] == 'o' && q[q.size() - 2] == 'm')
        {
            ans += 2;
            for(int i = 1; i <= 2; i ++ )
            {
                q.pop_back();
            }
        }
    }
    // cout << ans << endl;
    cout << (ans == n ? "Yes" : "No") << endl;
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