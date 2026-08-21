#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 998244353;
int qpow(int a, int b)
{
    int res = 1;
    while(b)
    {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> f(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        f[i] = i;
    }
    auto find = [&](auto self, int x) -> int{
        return (x == f[x] ? x : f[x] = self(self, f[x]));
    };
    auto merge = [&](int x, int y) -> void{
        if(find(find, x) != find(find, y)) f[find(find, x)] = find(find, y);
    };

    while(k -- )
    {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i ++ )
    {
        if(f[i] == i) cnt ++;
    }
    cout << qpow(26, cnt) << endl;
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