#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ull unsigned int
vector<ull> res;
void init()
{
    for(int i = 0; i <= 62; i ++ )
    {
        for(int j = 0; j <= i; j ++ )
        {
            res.push_back((1ULL << i) + (1ULL << j));
        }
    }
    // for(int i = 74; i <= 85; i ++ ) cout << res[i] << ' ';
    // cout << endl;
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
}
void solve()
{
    ull l, r;
    cin >> l >> r;
    // cout << "l r ";
    // cout << cnt << endl;
    // cout << binary(1, cnt, r) << ' ' << binary(1, cnt, l - 1) << endl;
    cout << upper_bound(res.begin(), res.end(), r) - lower_bound(res.begin(), res.end(), l) << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while(t -- )
    {
        solve();
    }
    return 0;
}