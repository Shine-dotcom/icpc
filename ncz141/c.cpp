#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    string a;
    cin >> a;
    int n = a.size();
    a = " " + a;
    for(int i = 1, j = n; i < j;)
    {
        if(a[i] == 'm' && a[j] == 'm')
        {
            i ++, j --;
            continue;
        }
        if(a[i] == 'n' && a[j] == 'n')
        {
            i ++, j --;
            continue;
        }
        if(a[i] == 'n' && a[j] == 'm')
        {
            if(i < n && a[i + 1] == 'n')
            {
                i += 2, j --;
                continue;
            }
            cout << "NO" << endl;
            return;
        }
        if(a[i] == 'm' && a[j] == 'n')
        {
            if(j > 1 && a[j - 1] == 'n')
            {
                i ++, j -= 2;
                continue;
            }
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
    cin >> t;
    while(t -- )
    {
        solve();
    }
    return 0;
}