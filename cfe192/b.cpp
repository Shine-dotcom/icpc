#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    vector<int> pre3(n + 1);
    for(int i = 1; i <= n; i ++ ) pre3[i] = pre3[i - 1] + (a[i] == 3);
    vector<int> pre2(n + 1), pre1(n + 1);
    for(int i = 1; i <= n; i ++ ) pre2[i] = pre2[i - 1] + (a[i] == 2), pre1[i] = pre1[i - 1] + (a[i] == 1);
    int idx = -1;
    for(int i = 1; i <= n; i ++ )
    {
        if(pre1[i] >= pre2[i] + pre3[i])
        {
            while(i < n - 2 && a[i + 1] == 3 && pre1[i + 1] >= pre2[i + 1] + pre3[i + 1]) i ++;
            idx = i;
            break;
        }
    }
    if(idx == -1)
    {
        cout << "NO" << endl;
        return;
    }
    for(int j = idx + 1; j < n; j ++ )
    {
        if(pre1[j] + pre2[j] - pre1[idx] - pre2[idx] >= pre3[j] - pre3[idx])
        {
            // cout << idx << ' ' << j << endl;
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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