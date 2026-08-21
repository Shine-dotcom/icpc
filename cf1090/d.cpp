#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[1] = 1;
    int j = 1;
    for(int i = 1; i <= n; i ++ )
    {
        a[i] = j * (j + 2);
        j += 2;
    }
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
    while(t -- )
    {
        solve();
    }
    return 0;
}