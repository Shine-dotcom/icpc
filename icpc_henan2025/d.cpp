#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    int a = 0;
    bool flag1 = 0, flag2 = 0;
    for(int i = 1; i * i <= n; i ++ )
    {
        if(i * i == n)
        {
            flag1 = 1;
        }
    }
    while(n)
    {
        a += n % 10;
        n /= 10;
    }
    for(int i = 1; i * i <= a; i ++ )
    {
        if(i * i == a)
        {
            flag2 = 1;
        }
    }
    if(flag1 && flag2)
    {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
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
    return 0;
}