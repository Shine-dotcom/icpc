#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<string> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        a[i] = " " + a[i];
    }
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        p[i] = i;
    }
    sort(p.begin() + 1, p.end(), [&](int x, int y){
        if(a[x][y] == '1') return x < y;
        else return x > y;
    });
    for(int i = 1; i <= n; i ++ ) cout << p[i] << ' ';
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
    return 0;
}