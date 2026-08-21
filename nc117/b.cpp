#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for(int i = 1; i <= 2 * n - 2; i ++ )
    {
        int x;
        cin >> x;
        cnt[x] ++;
    }
    for(int i = 1; i <= n; i ++ )
    {
        if(cnt[i] == n - 1)
        {
            cout << i << endl;
            return;
        }
    }
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