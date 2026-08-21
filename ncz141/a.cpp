#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    int a = -1;
    for(int i = 1; i * i <= n; i ++ )
    {
        if(i * i == n)
        a = i;
    }
    if(a == -1)
    {
        cout << "NO" << endl;
        return;
    }
    vector<int> dig1, dig2;
    while(n)
    {
        dig1.push_back(n % 10);
        n /= 10;
    }
    while(a)
    {
        dig2.push_back(a % 10);
        a /= 10;
    }
    int s = dig1.size(), t = dig2.size();
    for(int i = 1, j = s; i < j; i ++, j -- )
    {
        if(dig1[i] != dig1[j])
        {
            cout << "NO" << endl;
            return;
        }
    }
    for(int i = 1, j = t; i < j; i ++, j -- )
    {
        if(dig2[i] != dig2[j])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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