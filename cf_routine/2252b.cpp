#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> cnt(2), cntseg(2);
    for(int i = 1, j = 1; i <= n; i ++ )
    {
        while(j <= n && s[i] == s[j + 1])
        {
            j ++;
        }
        cnt[s[i] - '0'] += j - i;
        i = j ++;
        cntseg[s[i] - '0'] ++;
    }
    if(cnt[0] > cnt[1])
    {
        int need = cnt[0] - cnt[1] - 1;
        int available = cntseg[1] - cntseg[0] + 1;
        if(need <= available)
        {
            cout << cnt[0] + cnt[1] + need << endl;
            return;
        }
        cout << -1 << endl;
        return;
    }
    if(cnt[1] > cnt[0])
    {
        int need = cnt[1] - cnt[0] - 1;
        int available = cntseg[0] - cntseg[1] + 1;
        if(need <= available)
        {
            cout << cnt[0] + cnt[1] + need << endl;
            return;
        }
        cout << -1 << endl;
        return;
    }
    cout << cnt[0] + cnt[1] << endl;
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