#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    if(k > m)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<int> a(n + 1, 1);
    a[n] = m - k + 1;
    for(int i = 1; i <= n; i ++ )
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t -- ) solve();
    return 0;
}