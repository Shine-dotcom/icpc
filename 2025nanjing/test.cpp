#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int t = 0;
    for(int xn = 1; xn <= 9; xn ++ )
    {
        for(int yn = 1; yn <= 10; yn ++ )
        {
            for(int xr = 1; xr <= 9; xr ++ )
            {
                for(int yr = 1; yr <= 10; yr ++ )
                {
                    if(xn == xr && yn == yr) continue;
                    t ++;
                }
            }
        }
    }
    cout << t << endl;
    for(int xn = 1; xn <= 9; xn ++ )
    {
        for(int yn = 1; yn <= 10; yn ++ )
        {
            for(int xr = 1; xr <= 9; xr ++ )
            {
                for(int yr = 1; yr <= 10; yr ++ )
                {
                    if(xn == xr && yn == yr) continue;
                    cout << xn << ' ' << yn << ' ' << xr << ' ' << yr << endl;
                }
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t -- )
    {
        solve();
    }
    return 0;
}