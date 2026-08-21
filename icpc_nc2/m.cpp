#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, p;
    cin >> n >> p;
    vector<int> pri(1);
    int tmp = 1;
    while(tmp <= n)
    {
        tmp *= p;
        pri.push_back(tmp);
    }
    int res = 0;
    for(int i = 1; i < pri.size(); i ++ )
    {
        res += n / pri[i];
    }
    cout << res << endl;
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
    return 0;
}