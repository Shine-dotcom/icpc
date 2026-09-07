#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    if(n % 4 == 0)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<int> bit(32);
    for(int i = 0; i < 32; i ++ )
    {
        bit[i] = (n >> i) & 1;
    }
    for(int i = 0; i <= 31; i ++ )
    {
        if(bit[i] == 1 && bit[i + 1] == 0) bit[i] = -1;
        if(i >= 1 && bit[i - 1] == -1)
        {
            if(i == 31 || bit[i + 1] == 1)
            {
                bit[i] = 1;
                continue;
            }
            bit[i] = -1;
        }
    }
    for(int i = 0; i <= 31; i ++ )
    {
        cout << bit[i] << ' ';
        if(i % 8 == 7) cout << endl;
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