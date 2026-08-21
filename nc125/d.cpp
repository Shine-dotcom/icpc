#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int a;
    cin >> a;
    int t = a, cnt = 0;
    while(t)
    {
        t /= 10;
        cnt ++;
    }
    int s = 1;
    while(cnt -- && s < a)
    {
        s *= 10;
        s ++;
    }
    int s2 = (s / 10) * 9;
    int ans = (s - a) / 9 + 1 + (s - a) % 9;
    if(s2 >= a && (s2 - a) % 9 == 0)
    {
        ans = min((s2 - a) / 9, ans);
    }
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