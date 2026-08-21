#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(3 * n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        a[3 * i - 2] = i;
    }
    int j = n + 1;
    int i = 1;
    while(j <= 3 * n)
    {
        if(a[i] == 0)a[i] = j ++;
        i ++;
    }
    for(int k = 1; k <= 3 * n; k ++ )
    {
        cout << a[k] << ' ';
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
    return 0;
}