#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node{
    int val, l = 0, r = 1e18;
};
void solve()
{
    int n, k;
    cin >> n >> k;
    if(k < n || k > n * (n - 1) + 1)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    vector<vector<int>> a(n + 1, vector<int> (n + 1));
    int cnt = n * n;
    a[1][1] = k;
    for(int i = 2; i <= n; i ++ )
    {
        if(cnt == k) cnt --;
        a[i][i] = cnt --;
    }
    for(int i = 2; i <= n; i ++ )
    {
        for(int j = 1; j <= n; j ++ )
        {
            if(j == i) continue;
            if(cnt == k) cnt --;
            a[i][j] = cnt --;
        }
    }
    for(int i = 2; i <= n; i ++ )
    {
        if(cnt == k) cnt --;
        a[1][i] = cnt --;
    }
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= n; j ++ )
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
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