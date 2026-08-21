#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    int len = n;
    for(int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        sum += x;
        if(x == 0) len --;
    }
    cout << min(sum + 1 - n, len) << endl;
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