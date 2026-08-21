#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s = " " + s, t = " " + t;
    bool bj = 1;
    string r1 = " ", r2 = " ";
    for(int i = 1; i <= n; i ++ )
    {
        if(s[i] == t[i]) r1.push_back(s[i]), r2.push_back(t[i]);
        else
        {
            if(bj) r1.push_back('('), r2.push_back(')');
            else r1.push_back(')'), r2.push_back('(');
            bj ^= 1;
        }
    }
    int cnt1 = 0, cnt2 = 0;
    bj = 1;
    // cout << r1 << endl;
    // cout << r2 << endl;
    for(int i = 1; i <= n; i ++ )
    {
        if(r1[i] == '(') cnt1 ++; else cnt1 --;
        if(r2[i] == '(') cnt2 ++; else cnt2 --;
        if(cnt1 < 0 || cnt2 < 0) bj = 0;
    }
    if(cnt1 != 0 || cnt2 != 0) bj = 0;
    cout << (bj ? "YES" : "NO") << endl;
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