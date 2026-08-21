#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int a, b, l, r;
    cin >> a >> b >> l >> r;
    
    int left = 0, right = 0;
    if(l - b <= b - a)
    {
        left = l - b, right = min(r - b, b - a);
    }
    else
    {
        cout << 0 << endl;
        return;
    }
    int res = 0;
    for(int i = 1; i * i <= (b - a); i ++ )
    {
        if(i * i != (b - a) && !((b - a) % i) && left <= i && i <= right) res ++;
        if(i * i != (b - a) && !((b - a) % i) && left <= (b - a) / i && (b - a) / i <= right) res ++;
        if(i * i == (b - a)) res ++;
    }
    cout << res << endl;
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
