#include<bits/stdc++.h>
using namespace std;
#define int long long
// #define endl '\n'
void solve()
{
    int n;
    cin >> n;
    for(int i = 2; i <= n; i ++ )
    {
        cout << "? " << 2 * i - 1 << ' ' << 2 * i << endl;
        int ans;
        cin >> ans;
        if(ans)
        {
            cout << "! " << 2 * i << endl;
            return;
        }
    }
    int t1, t2;
    cout << "? 1 3" << endl;
    cin >> t1;
    if(t1)
    {
        cout << "! 1" << endl;
        return;
    }
    cout << "? 1 4" << endl;
    cin >> t2;
    if(t2)
    {
        cout << "! 1" << endl;
        return;
    }
    cout << "! 2" << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t -- )
    {
        solve();
    }
}