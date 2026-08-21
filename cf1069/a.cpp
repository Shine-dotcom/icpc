#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> flag(1001);
    int cnt = 0;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        if(flag[a[i]]) continue;
        flag[a[i]] = 1;
        cnt ++;
    }
    while(!flag[cnt]) cnt ++;
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