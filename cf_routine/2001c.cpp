#include<bits/stdc++.h>
using namespace std;
#define int long long
// #define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> stk;
    for(int i = 2; i <= n; i ++ )
    {
        stk.push_back(i);
    }
    vector<pair<int, int>> e;
    vector<int> in_tree(n + 1);
    in_tree[1] = 1;
    while(!stk.empty())
    {
        int x = stk.back();
        stk.pop_back();
        if(in_tree[x]) continue;
        int l = 1, r = x, q;
        while(1)
        {
            // for(auto x : stk)
            // {
            //     cout << x << ' ';
            // }
            // cout << endl;
            cout << "? " << l << ' ' << r << endl;
            cin >> q;
            if(q == l)
            {
                in_tree[r] = 1;
                e.push_back({l, r});
                break;
            }
            if(in_tree[q]) l = q;
            else r = q;
        }
        stk.push_back(x);
        // cout << endl;
    }
    cout << "! ";
    for(auto x : e)
    {
        cout << x.first << ' ' << x.second << ' ';
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
    return 0;
}