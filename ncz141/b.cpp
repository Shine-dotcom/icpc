#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int x, y;
    cin >> x >> y;
    int idx = -1;
    for(int i = 31; i >= 0; i -- )
    {
        if(((x >> i) & 1) ^ ((y >> i) & 1))
        {
            idx = i;
            break;
        }
    }
    cout << (1 << idx) << endl;
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