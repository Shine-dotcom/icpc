#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> pre(n + 1), suf(n + 1), a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
    }
    suf[n] = a[n];
    for(int i = n - 1; i >= 1; i -- )
    {
        suf[i] = suf[i + 1] ^ a[i];
    }
    for(int i = 1; i <= n; i ++ )
    {
        cout << pre[i] << ' ';
    }
    cout << endl;
    for(int i = 1; i <= n; i ++ )
    {
        cout << suf[i] << ' ';
    }
    cout << endl;
    int l = -1, r = -1;
    for(int i = 1; i <= n; i ++ )
    {
        if(pre[i] == pre[n])
        {
            l = i;
            break;
        }
    }
    for(int i = n; i >= 1; i -- )
    {
        if(suf[i] == suf[1])
        {
            r = i;
            break;
        }
    }
    if(r == -1 || l == -1)
    {
        cout << 0 << endl;
        return;
    }
    int cnt = 2;
    for(int i = l + 1, i < r; i ++ )
    {
        if(pre[i] == pre[l]) cnt ++;
    }
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