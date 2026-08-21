#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, x, s;
    cin >> n >> x >> s;
    string s0;
    cin >> s0;
    s0 = " " + s0;
    int capa = 0;
    int cnti = 0, l = 0;
    for(int i = 1; i <= n; i ++ )
    {
        if(s0[i] == 'I')
        {
            if(l == x) continue;
            cnti = min(cnti + 1, x), l ++;
            capa ++;
        }
        if(s0[i] == 'E')
        {
            if(capa == cnti * s) continue;
            if(capa >= l * s) l ++;
            capa ++;
        }
        if(s0[i] == 'A')
        {
            cnti = min(cnti + 1, x);
            if(capa == cnti * s) continue;
            if(capa >= l * s) l ++;
            capa ++;
        }
        // cout << capa << ' ' << cnti << ' ' << l << endl;
    }
    cout << capa << endl;
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