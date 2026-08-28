#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    map<pair<string, char>, bool> mp;
    for(int i = 1; i <= n; i ++ )
    {
        string team, status;
        char id;
        cin >> team >> id >> status;
        bool st = (status == "accepted" ? 1 : 0);
        mp[{team, id}] |= st;
    }
    vector<int> cnt(26);
    for(auto x : mp)
    {
        char id = x.first.second;
        if(x.second) cnt[id - 'A'] ++;
    }
    int mx = -1, idx = 0;
    for(int i = 0; i < 26; i ++ )
    {
        // cout << cnt[i] << ' ';
        if(cnt[i] > mx)
        {
            mx = cnt[i];
            idx = i;
        }
    }
    char c = idx + 'A';
    cout << c << endl;
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