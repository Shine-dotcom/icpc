#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> dsu(2 * n + 1);
    auto find = [&](auto self, int x) -> int {
        return (dsu[x] == x ? x : self(self, dsu[x]));
    };
    auto merge = [&](int x, int y) -> void {
        if(find(find, x) != find(find, y))
        dsu[find(find, x)] = find(find, y);
    };
    for(int i = 1; i <= 2 * n; i ++ )
    {
        dsu[i] = i;
    }
    vector<int> ans;
    for(int i = 1; i <= n; i ++ )
    {
        int x, y;
        cin >> x >> y;
        if(find(find, x) != find(find, y))
        {
            ans.push_back(i);
            merge(x, y);
        }
    }
    cout << ans.size() << endl;
    for(auto x : ans)
    {
        cout << x << ' ';
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