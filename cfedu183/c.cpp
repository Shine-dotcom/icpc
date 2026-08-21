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
    vector<int> pre(n + 1);
    s = " " + s;
    int flag = 0;
    for(int i = 1; i <= n; i ++ )
    {
        int x = (s[i] == 'a' ? 1 : -1);
        pre[i] = pre[i - 1] + x;
    }
    if(pre[n] == 0)
    {
        cout << 0 << endl;
        return;
    }
    int res = n;
    int cnt = 0;
    int flag2 = 0;
    map<int, int> lst;
    lst[0] = 0;
    for(int i = 1; i <= n; i ++ )
    {
        lst[pre[i]] = i;
        if(lst.count(pre[i] - pre[n]))
        {
            res = min(res, i - lst[pre[i] - pre[n]]);
        }
    }
    cout << (res == n ? -1 : res) << endl;
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