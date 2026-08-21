#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 676767677;
void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    int flag = 0;
    for(int i = 1; i <= n; i ++ )
    {
        int a;
        cin >> a;
        if(a == 1)
        {
            flag = 1;
            continue;
        }
        sum = (sum + a) % mod;
        flag = 0;
    }
    cout << (sum + flag) % mod << endl;
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