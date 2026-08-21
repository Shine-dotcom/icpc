#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 100, T = 1e5 + 5;
struct node{
    int a, b, c;
    bool operator < (const node &u) const {
        return c * u.b < u.c * b;
    }
} arr[N];
int t, n, dp[T];
void solve()
{
    for(int i = 0; i < N; i ++ )
    {
        arr[i] = {0, 0, 0};
    }
    for(int i = 0; i < T; i ++ ) dp[i] = 0;
    cin >> t >> n;
    for(int i = 1; i <= n; i ++ ) cin >> arr[i].a;
    for(int i = 1; i <= n; i ++ ) cin >> arr[i].b;
    for(int i = 1; i <= n; i ++ ) cin >> arr[i].c;
    sort(arr + 1, arr + 1 + n);
    for(int i = 1; i <= n; i ++ )
    {
        int a = arr[i].a, b = arr[i].b, c = arr[i].c;
        for(int j = t; j >= c; j -- )
        {
            dp[j] = max(dp[j], dp[j - c] + a - j * b);
        }
    }
    int ans = 0;
    for(int i = 0; i <= t; i ++ )
    {
        ans = max(ans, dp[i]);
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