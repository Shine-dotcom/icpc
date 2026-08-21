#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    vector<double> a(9), b(9);
    for(int i = 1; i <= 8; i ++ )
    {
        cin >> a[i] >> b[i];
    }
    vector<vector<int>> idx;
    vector<int> flag(9), tmp;
    auto dfs = [&](auto self, int dep) -> void{
        if(dep >= 8)
        {
            idx.push_back(tmp);
            return;
        }
        for(int i = 1; i <= 8; i ++ )
        {
            if(flag[i]) continue;
            flag[i] = 1;
            tmp.push_back(i);
            self(self, dep + 1);
            tmp.pop_back();
            flag[i] = 0;
        }
    };
    dfs(dfs, 0);
    // for(auto x : idx)
    // {
    //     for(auto u : x)
    //     cout << u << ' ';
    //     cout << endl;
    // }
    auto p = [&](int i, int j) -> double{
        if(i < j)
        {
            return a[i] / (a[i] + b[j]);
        }
        return b[i] / (b[i] + a[j]);
    };
    auto p1 = [&](int i, int j, int k) -> double{
        return p(i, j) * p(j, k) + p(i, k) * p(k, j);
    };
    auto p2 = [&](int i, int j, int k, int l, int h) -> double{
        double f1 = p(i, j);
        double f2 = p1(j, l, h) + p1(k, l, h) + p1(l, j, k) + p1(h, j, k);
        return f1 * f2;
    };
    double ans = 0;
    for(auto tup : idx)
    {
        vector<double> pp(8);
        pp[0] = p(tup[0], tup[1]) * p1(tup[0], tup[2], tup[3]) * p2(tup[0], tup[4], tup[5], tup[6], tup[7]);
        pp[1] = p(tup[1], tup[0]) * p1(tup[1], tup[2], tup[3]) * p2(tup[1], tup[4], tup[5], tup[6], tup[7]);
        pp[2] = p(tup[2], tup[3]) * p1(tup[2], tup[0], tup[1]) * p2(tup[2], tup[4], tup[5], tup[6], tup[7]);
        pp[3] = p(tup[3], tup[2]) * p1(tup[3], tup[0], tup[1]) * p2(tup[3], tup[4], tup[5], tup[6], tup[7]);
        pp[4] = p(tup[4], tup[5]) * p1(tup[4], tup[6], tup[7]) * p2(tup[4], tup[0], tup[1], tup[2], tup[3]);
        pp[5] = p(tup[5], tup[4]) * p1(tup[5], tup[6], tup[7]) * p2(tup[5], tup[0], tup[1], tup[2], tup[3]);
        pp[6] = p(tup[6], tup[7]) * p1(tup[6], tup[4], tup[5]) * p2(tup[6], tup[0], tup[1], tup[2], tup[3]);
        pp[7] = p(tup[7], tup[6]) * p1(tup[7], tup[4], tup[5]) * p2(tup[7], tup[0], tup[1], tup[2], tup[3]);
        for(int i = 0; i < 8; i ++ )
        {
            if(tup[i] == 1)
            {
                ans = max(ans, pp[i]);
            }
        }
    }
    cout << ans << endl;
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
}