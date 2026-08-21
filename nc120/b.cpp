#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int l, r;
    cin >> l >> r;
    int len = r - l + 1;
    int a, b, c;
    a = b = c = len / 3;
    if(len % 3 == 1)
    {
        int pos = l % 3;
        if(pos == 1)
        {
            a ++;
        }
        else if(pos == 2)
        {
            b ++;
        }
        else
        {
            c ++;
        }
        cout << a << ' ' << b << ' ' << c << endl;
        return;
    }
    if(len % 3 == 2)
    {
        int pos = l % 3;
        if(pos == 1)
        {
            b ++, c ++ ;
        }
        else if(pos == 2)
        {
            a ++, c ++ ;
        }
        else
        {
            a ++, b ++ ;
        }
        cout << a << ' ' << b << ' ' << c << endl;
        return;
    }
    cout << a << ' ' << b << ' ' << c << endl;
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
