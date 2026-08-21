#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    string status;
    cin >> status;
    // cout << status << endl;
    int n;
    if(status == "first")
    {
        // cout << 111 << endl;
        cin >> n;
        vector<int> a(n + 1);
        vector<char> s;
        for(int i = 1; i <= n; i ++ )
        {
            cin >> a[i];
            s.push_back(a[i] + 'a' - 1);
        }
        for(auto x : s)
        cout << x;
        cout << endl;
    }
    else
    {
        // cout << 222 << endl;
        string t;
        cin >> t;
        t = " " + t;
        cout << t.size() - 1 << endl;
        for(int i = 1; i <= t.size() - 1; i ++ )
        {
            cout << (int)(t[i] - 'a' + 1) << ' ';
        }
        cout << endl;
    }
    // cout << 333 << endl;
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