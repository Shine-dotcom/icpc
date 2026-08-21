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
    int flag = 1;
    for(int i = 1; i <= n; i ++ )
    {
        if(s[i] == '0') flag = 0;
    }
    if(!flag)
    {
        for(int i = 2; i <= n; i ++ ) cout << "&";
        cout << endl;
        return;
    }
    cout << "^";
    for(int i = 3; i <= n; i ++ ) cout << "&";
    cout << endl;
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