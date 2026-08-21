#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    vector<int> a(8);
    for(int i = 1; i <= 7; i ++ )
    {
        cin >> a[i];
    }
    int sum = 0;
    sort(a.begin() + 1, a.end());
    for(int i = 1; i <= 6; i ++ )
    {
        sum += a[i];
    }
    cout << a[7] - sum << endl;
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
    return 0;
}