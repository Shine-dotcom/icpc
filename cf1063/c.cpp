#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int> (n + 1));
    for(int i = 0; i <= 1; i ++ )
    {
        for(int j = 1; j <= n; j ++ )
        {
            cin >> a[i][j];
        }
    }
    vector<set<int>> st(2);
    st[0].insert(1e9);
    st[1].insert(-1e9);
    vector<vector<pair<int, int>>> pos(2 * n + 1);
    for(int i = 0; i <= 1; i ++ )
    {
        for(int j = 1; j <= n; j ++ )
        {
            pos[a[i][j]].push_back({i, j});
        }
    }
    for(int i = 1; i <= n; i ++ ) st[0].insert(i);
    for(int i = 1; i <= n; i ++ ) st[1].insert(i);
    
    auto del = [&](int x) -> void{
        for(auto [i, j] : pos[x])
        {
            st[i].insert(j);
        }
    };

    auto add = [&](int x) -> void{
        for(auto [i, j] : pos[x])
        {
            st[i].erase(j);
        }
    };

    auto check = [&]() -> bool{
        if(st[0].count(1)) return 0;
        if(st[1].count(n)) return 0;
        if(*st[0].begin() - 1 <= *st[1].rbegin()) return 0;
        return 1;
    };
    // cout << *st[0].begin() << ' ' << *st[1].rbegin() << endl;
    int r = 0, res = 0;
    for(int i = 1; i <= 2 * n; i ++ )
    {
        while(r + 1 <= 2 * n && !check()) 
        {
            add( ++ r);
        }
        if(!check()) break;
        res += 2 * n - r + 1;
        del(i);
    }
    cout << res << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t -- )
    {
        solve();
    }
}