#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> cnt(3);
    string s;
    cin >> s;
    for(auto x : s)
    {
        cnt[x - '0'] ++;
    }
    vector<char> res(n + 1, '+');
    if(s.size() == n)
    {
        for(int i = 1; i <= n; i ++ )
        {
            cout << "-";
        }
        cout << endl;
        return;
    }
    for(int i = 1; i <= cnt[0]; i ++ )
    {
        res[i] = '-';
    }
    for(int i = 1; i <= cnt[1]; i ++ )
    {
        res[n - i + 1] = '-';
    }
    for(int i = 1; i <= cnt[2]; i ++ )
    {
        res[i + cnt[0]] = '?';
        res[n - cnt[1] - i + 1] = '?';
    }
    for(int i = 1; i <= n; i ++ )
    {
        cout << res[i];
    }
    cout << endl;
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