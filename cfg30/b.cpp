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
    int flag = 0;
    for(int i = 1; i <= n && !flag; i ++ )
    {
        for(int j = i + 1; j <= n && !flag; j ++)
        {
            if((a[j] % a[i]) % 2 == 0)
            {
                cout << a[i] << ' ' << a[j] << endl;
                flag = 1;
            }
        }
    }
    if(!flag)
    {
        cout << -1 << endl;
    }
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