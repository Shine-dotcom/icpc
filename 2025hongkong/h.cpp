#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    for(int i = 2; i <= n; i ++ )
    {
        if(s[i] == s[i - 1])
        {
            cout << n - 1 << endl;
            return;
        }
    }
    cout << n - 2 << endl;
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