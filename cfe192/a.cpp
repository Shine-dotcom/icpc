#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    int cnt3 = 0, cnt2 = 0;
    for(int i = 1; i <= n; i ++ )
    {
        if(a[i] == 2) cnt2 ++;
        if(a[i] >= 3) cnt3 ++;
    }
    if(cnt3 >= 1 || cnt2 >= 2)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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
}