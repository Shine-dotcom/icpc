#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> p[i];
    vector<int> s(n + 1);
    for(int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + p[i];
    int sum = 0;
    for(int i = 1; i <= n; i ++ )
    {
        sum += (s[n] - s[i]) - p[i] * (n - i);
    }
    cout << sum << endl;
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