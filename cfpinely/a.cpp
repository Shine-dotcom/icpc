#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int r, x, d, n;
    cin >> r >> x >> d >> n;
    string s;
    cin >> s;
    s = " " + s;
    int delta = r - x;
    int cnt = 0;
    if(r == 0 && x == 1)
    {
        int flag = 0;
        for(int i = 1; i <= n; i ++ )
        {
            if(s[i] == '2')
            {
                flag = 1;
                continue;
            }
            cnt += flag;
            cnt ++;
            flag = 0;
        }
        cout << cnt << endl;
        return;
    }
    if(delta < 0)
    {
        cout << s.size() - 1 << endl;
        return;
    }
    int times = delta / d + 1;
    int flag2 = 0;
    for(int i = 1; i <= n; i ++ )
    {
        if(s[i] == '1')
        {
            cnt ++;
        }
        if(s[i] == '2')
        {
            cnt += flag2;
        }
        if(times <= cnt && !flag2)
        {
            flag2 = 1;
        }
    }
    cout << cnt << endl;
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