#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 1; i <= 20; i ++ )
    {
        int n = s.size();
        string t1;
        for(int j = 0; j < n / 2; j ++ )
        {
            t1.push_back(s[j]);
        }
        string t2;
        for(int j = n / 2; j < n; j ++ )
        {
            if(s[j] != 'z')
                t2.push_back(s[j] + 1);
            else
                t2.push_back('a');
        }
        s = t1 + s + t2;
        n = s.size();
        for(int j = n - m; j < n; j ++ )
        {
            cout << s[j];
        }
        cout << endl;
    }
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