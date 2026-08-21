#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct line {
    int pos, st, ed;
};
void solve()
{
    int l, r, x;
    cin >> l >> r >> x;
    auto f = [&](int x) -> int {
        if(x % 4 == 0) return x;
        if(x % 4 == 1) return 1;
        if(x % 4 == 2) return x + 1;
        return 0;
    };
    l = (l + x - 1) / x;
    r /= x;
    int ans = f(r) ^ f(l - 1) * x;
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t -- )
    {
        solve();
    }
    return 0;
}
// 我有个想法，把横线全部存进vector<pair<int, int>> hor(4)中，垂线同理