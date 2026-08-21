#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int m = b.size() - 1;
    vector<int> cnt(m);
    for(int i = 1; i <= n; i ++ )
    {
        int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        cnt[idx] ++;
    }
    for(int i = m; i >= 1; i -- )
    {
        if(cnt[i] % 2)
        {
            cout << "red" << endl;
            return;
        }
    }
    cout << "fang" << endl;
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