#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    bool flag = 0;
    for(int i = 1; i <= n; i ++ )
    {
        int a;
        cin >> a;
        if(a == 100)
            flag = 1;
    }
    cout << (flag ? "Yes" : "No") << endl;
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