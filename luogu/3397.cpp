#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e3 + 10;
int d[N][N];
void solve()
{
    int n, m;
    cin >> n >> m;
    while(m -- )
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        d[x1][y1] ++;
        d[x1][y2 + 1] --;
        d[x2 + 1][y1] --;
        d[x2 + 1][y2 + 1] ++;
    }
    for(int i = 1; i <= n; i ++ )
        for(int j = 1; j <= n; j ++ )
            d[i][j] += d[i - 1][j];
    
    for(int i = 1; i <= n; i ++ )
        for(int j = 1; j <= n; j ++ )
            d[i][j] += d[i][j - 1];
    
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= n; j ++ )
        {
            cout << d[i][j] << " \n"[j == n];
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t -- ) solve();
    return 0;
}