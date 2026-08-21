#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;
    int ans = 0, cnt = 0;
    int flag = 0;
    int l = -1, r = -1;
    for(int i = n, j = n; i >= 1; i --, j -- )
    {
        if(s[i] == '1') flag = 1;
        if(flag == 0) continue;
        while(j >= 1 && s[j - 1] == '0')
        {
            j -- ;
        }
        // cout << 111 << ' ' << j - i + 1 << endl;
        if(i - j >= k - 1) 
        {
            // cout << 222 << ' ' << i << ' ' << j << endl;
            ans ++;
        }
        l = j, r = i;
        i = j;
    }
    if(r - l >= k - 1 || r == -1 && l == -1)
    cout << ans << endl;
    else
    cout << ans + 1 << endl;
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