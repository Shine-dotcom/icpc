#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e5 + 10;
int a[N], f[20][N];
void solve()
{
    int m, n;
    cin >> m >> n;
    for(int i = 1; i <= m; i ++ ) cin >> a[i], f[0][i] = a[i];
    int k = log2(m);
    for(int i = 1; i <= k; i ++ )
    {
        for(int j = 1; j + (1 << i) - 1 <= m; j ++ )
        {
            f[i][j] = min(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
        }
    }
    while(n -- )
    {
        int l, r;
        cin >> l >> r;
        int s = log2(r - l + 1);
        cout << min(f[s][l], f[s][r - (1 << s) + 1]) << ' ';
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t -- ) solve();
    return 0;
}