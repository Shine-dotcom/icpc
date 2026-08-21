#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e5 + 10;
int t[N], n, T;
bool check(int x)
{
    for(int i = 1; i <= n; i ++ )
    {
        if(t[i] > x * T) return 0;
    }
    return 1;
}
void solve()
{
    cin >> n >> T;
    for(int i = 1; i <= n; i ++ ) cin >> t[i];
    int l = 2, r = 1e9;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt = 1;
    // cin >> t;
    while(tt -- )
    {
        solve();
    }
    return 0;
}