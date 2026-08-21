#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int ksm(int a, int b)
{
    int ans = 1;
    while(b)
    {
        if(b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    int a, b;
    cin >> a >> b;
    int res = 0;
    int res2 = 0;
    int ans;
    for(int i = 0; i <= 30; i ++ )
    {
        if((1 - ksm(4, i + 1)) / -3 > a)
        {
            res = i;
            break;
        }
    }
    for(int i = 0; i <= 30; i ++ )
    {
        if(2 * (1 - ksm(4, i + 1)) / -3 > b)
        {
            res2 = i;
            break;
        }
    }
    if(res > res2 + 1) res = res2 + 1;
    else if(res2 > res) res2 = res;
    ans = res + res2;
    for(int i = 0; i <= 30; i ++ )
    {
        if(2 * (1 - ksm(4, i + 1)) / -3 > a)
        {
            res2 = i;
            break;
        }
    }
    for(int i = 0; i <= 30; i ++ )
    {
        if((1 - ksm(4, i + 1)) / -3 > b)
        {
            res = i;
            break;
        }
    }
    if(res > res2 + 1) res = res2 + 1;
    else if(res2 > res) res2 = res;
    ans = max(ans, res + res2);
    cout << ans << endl;
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