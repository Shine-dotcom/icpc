#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1), cnt_a(n + 1), cnt_b(n + 1);
    multiset<int> msa, msb;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    for(int i = 1; i <= n; i ++ ) cin >> b[i];
    for(int i = 1; i <= k; i ++ )
    {
        cnt_a[a[i]] ++;
        if(b[i] != -1) cnt_b[b[i]] ++;
    }
    for(int i = 1; i <= n; i ++ )
    {
        if(cnt_b[i] > cnt_a[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    for(int i = k + 1; i <= n; i ++ )
    {
        if(a[i] == a[i - k])
        {
            if(b[i] != -1 && b[i - k] != -1 && b[i] != b[i - k])
            {
                cout << "NO" << endl;
                return;
            }
        }
        if(a[i] != a[i - k])
        {
            if(b[i] != -1 && a[i] != b[i])
            {
                cout << "NO" << endl;
                return;
            }
            if(b[i - k] != -1 && a[i - k] != b[i - k])
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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