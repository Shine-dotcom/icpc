#include<bits/stdc++.h>
using namespace std;
#define int long long
// #define endl '\n'
void solve()
{
    int n;
    cin >> n;
    int a, p;
    cout << "1 " << 1 << ' ' << n << endl;
    cin >> p;
    cout << "2 " << 1 << ' ' << n << endl;
    cin >> a;
    int l = 1, r = n;
    while(l < r)
    {
        int pl, al;
        int mid = (l + r) >> 1;
        cout << "1 " << l << ' ' << mid << endl;
        cin >> pl;
        cout << "2 " << l << ' ' << mid << endl;
        cin >> al;
        if(pl < al)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << "! " << l << ' ' << l - p + a - 1 << endl;
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