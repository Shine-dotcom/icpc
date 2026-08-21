#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node{
    int i;
    char c;
};
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<node> u, l;
    for(int i = 1; i <= n; i ++ )
    {
        if(s[i - 1] == 'B')
        {
            if(u.size()) u.pop_back();
            continue;
        }
        if(s[i - 1] == 'b')
        {
            if(l.size()) l.pop_back();
            continue;
        }
        if(s[i - 1] >= 'a' && s[i - 1] <= 'z') l.push_back({i, s[i - 1]});
        if(s[i - 1] >= 'A' && s[i - 1] <= 'Z') u.push_back({i, s[i - 1]});
    }
    // for(auto x : l) cout << x.c;
    // cout << endl;
    // for(auto x : u) cout << x.c;
    // cout << endl;
    int i = 0, j = 0;
    while(i < u.size() || j < l.size())
    {
        if(i < u.size() && (j == l.size() || u[i].i < l[j].i))
        {
            cout << u[i ++ ].c;
            continue;
        }
        cout << l[j ++ ].c;
    }
    // if(l.empty())
    // {
    //     for(auto x : u) cout << x.c;
    // }
    cout << endl;
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