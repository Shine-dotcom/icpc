#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve()
{
    int n;
    cin >> n;
    if(n <= 2)
    {
        cout << "red" << endl;
        return;
    }
    if(n % 2 == 0)
    {
        cout << "purple" << endl;
        return;
    }
    cout << "red" << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t -- )
    {
        solve();
    }
}