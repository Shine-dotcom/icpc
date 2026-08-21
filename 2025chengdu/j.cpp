#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m, k, b;
    cin >> n >> m >> k >> b;
    int ac = 0;
    for(int i = 1; i <= n; i ++ )
    {
        int sum = 0, flag = 0;
        for(int j = 1; j <= m; j ++ )
        {
            int s;
            cin >> s;
            sum += s;
            if(s <= 0) flag ++ ;
            else flag --;
        }
        // cout << sum << ' ' << flag << endl;
        if(sum >= k)
        {
            ac ++;
            continue;
        }
        if(sum + flag >= k && b > 0) b --, ac ++;
    }
    cout << ac << endl;
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