#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, a;
    cin >> n >> a;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> v[i];
    }
    int idx = lower_bound(v.begin(), v.end(), a) - v.begin();
    if(v[idx] == a)
    {
        int len = upper_bound(v.begin(), v.end(), a) - idx - v.begin();
        if(n == len)
        {
            cout << 0 << endl;
            return;
        }
        if(idx - 1 > (n - len) / 2)
        {
            cout << v[idx - 1] << endl;
            return;
        }
        cout << v[idx + len] << endl;
        return;
    }
    if(v[idx] != a)
    {
        idx --;
    }
    if(idx <= n / 2)
    {
        cout << a + 1 << endl;
        return;
    }
    cout << a - 1 << endl;
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