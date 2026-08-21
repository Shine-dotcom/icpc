#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> st(n + 1);
    while(q -- )
    {
        int c, l, r;
        cin >> c >> l >> r;
        for(int i = l; i <= r; i ++ )
        {
            if(st[i] != c && st[i])
            {
                st[i] = -1;
                continue;
            }
            st[i] = c;
        }
    }
    vector<int> a(n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i ++ )
    {
        if(st[i])
        {
            if(st[i] == 1)
            {
                a[i] = k;
            }
            if(st[i] == 2)
            {
                a[i] = cnt;
                cnt = (cnt + 1) % k;
            }
            if(st[i] == -1)
            {
                a[i] = k + 1;
            }
        }
        else
        {
            cnt = 0;
        }
    }
    for(int i = 1; i <= n; i ++ )
    {
        cout << a[i] << ' ';
    }
    cout << endl;
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