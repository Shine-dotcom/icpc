#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int xk, yk, xr, yr;
    cin >> xk >> yk >> xr >> yr;
    int dx[] = {1, -1, -2, -2, -1, 1, 2, 2};
    int dy[] = {2, 2, 1, -1, -2, -2, -1, 1};
    vector<int> flag(8);
    if(xr == xk && yr == yk + 1) flag[0] = flag[1] = 1;
    if(yr == yk && xr == xk - 1) flag[2] = flag[3] = 1;
    if(xr == xk && yr == yk - 1) flag[4] = flag[5] = 1;
    if(yr == yk && xr == xk + 1) flag[6] = flag[7] = 1;
    for(int i = 0; i < 8; i ++ )
    {
        if(flag[i]) continue;
        if(xk + dx[i] <= 0 || yk + dy[i] <= 0 || xk + dx[i] > 9 || yk + dy[i] > 10) continue;
        if(xk + dx[i] != xr && yk + dy[i] != yr)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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