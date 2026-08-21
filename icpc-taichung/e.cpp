#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i *= 10)
    {
        cnt ++;
    }
    vector<int> tmp(1);
    vector<int> flag(cnt + 1);
    vector<vector<int>> ans(1);
    auto dfs = [&](auto self, int dep) -> void {
        if(dep == cnt)
        {
            ans.push_back(tmp);
            return;
        }
        for(int i = 1; i <= cnt; i ++ )
        {
            if(!flag[i])
            {
                flag[i] = 1;
                tmp.push_back(i);
                self(self, dep + 1);
                tmp.pop_back();
                flag[i] = 0;
            }
        }
    };
    dfs(dfs, 0);
    int j, k;
    cin >> j >> k;
    // for(int i = 1; i < ans.size(); i ++ )
    // {
    //     for(int j = 1; j < ans[i].size(); j ++ )
    //     {
    //         cout << ans[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    int a = 0, b = cnt;
    for(int i = 1; i < ans[1].size(); i ++ )
    {
        if(ans[j][i] == ans[k][i])
        {
            a ++, b --;
        }
    }
    cout << a << "A" << b << "B" << endl;
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