#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    set<char> st;
    for(int i = 1; i <= n; i ++ )
    {
        string s;
        cin >> s;
        st.insert(s[0] - 'a' + 'A');
    }
    // for(auto x : st)
    // {
    //     cout << x;
    // }
    // cout << endl;
    for(int i = 1; i <= m; i ++ )
    {
        string t;
        cin >> t;
        for(auto x : t)
        {
            // cout << x << endl;
            if(st.find(x) == st.end())
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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
    return 0;
}