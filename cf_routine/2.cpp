#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++ )
    {
        cin >> b[i];
    }
    vector<vector<int>> sta(21, vector<int> (n + 1)), stb(21, vector<int> (n + 1));
    for(int i = 0; i <= 20; i ++ )
    {
        for(int j = 1; j <= n; j ++ )
        {
            sta[i][j] = (a[j] >> i) & 1;
            stb[i][j] = (b[j] >> i) & 1;
        }
    }
    for(int i = 20; i >= 0; i -- )
    {
        int cnt = 0, flag = -1;
        for(int j = 1; j <= n; j ++ )
        {
            if(sta[i][j] ^ stb[i][j])
            cnt ++, flag = j;
        }
        if(cnt & 1)
        {
            cout << (flag & 1 ? "Ajisai" : "Mai") << endl;
            return;
        }
    }
    cout << "Tie" << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t -- )
    {
        solve();
    }
    return 0;
}

// https://codeforces.com/problemset/problem/2171/C2