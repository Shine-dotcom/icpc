#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    int cnt0 = 0;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i], sum += a[i];
        if(a[i] == 0) cnt0 ++;
    }
    if(200 - n >= 2 * sum || 200 + n - cnt0 < 2 * sum)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    vector<int> b = a;
    if(sum < 100)
    {
        for(int i = 1; i <= n; i ++ )
        {
            b[i] *= n;
            b[i] += (100 - sum);
            cout << b[i] << ' ';
        }
        cout << endl;
        return;
    }
    if(sum == 100)
    {
        for(int i = 1; i <= n; i ++ ) cout << b[i] << ' ';
        cout << endl;
        return;
    }
    int tmp = sum * 10;
    for(int i = 1; i <= n; i ++ )
    {
        b[i] *= 10;
        if(b[i])
        {
            if(tmp <= 1000) continue;
            b[i] -= 5;
            tmp -= 5;
        }
    }
    for(int i = 1; i <= n; i ++ )
    {
        cout << b[i] << ' ';
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