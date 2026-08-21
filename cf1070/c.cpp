#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> even;
    int mx_odd = 0, cnt_odd = 0;
    for(int i = 1; i <= n; i ++ )
    {
        int a;
        cin >> a;
        if(a & 1) mx_odd = max(mx_odd, a), cnt_odd ++ ;
        else even.push_back(a);
    }
    if(cnt_odd == 0)
    {
        for(int i = 1; i <= n; i ++ )
        {
            cout << 0 << ' ';
        }
        cout << endl;
        return;
    }
    vector<int> sum(n + 1);
    sum[1] = mx_odd;
    sort(even.begin(), even.end(), [&](int x, int y){
        return x > y;
    });
    for(int i = 2; i <= n; i ++ )
    {
        if(i <= even.size() + 1)
        {
            sum[i] = sum[i - 1] + even[i - 2];
            continue;
        }
        sum[i] = sum[i - 2];
    }
    if(cnt_odd % 2 == 0) sum[n] = 0;
    for(int i = 1; i <= n; i ++ )
    {
        cout << sum[i] << ' ';
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