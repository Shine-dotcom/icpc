#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    s1 = " " + s1, s2 = " " + s2;
    vector<int> swp1, swp2;
    int p = 0;
    for(int i = 1; i <= n; i ++ )
    {
        if(s1[i] == '1' && s2[i] == '0')
        {
            swp1.push_back(i);
            p ++;
        }
        if(s1[i] == '0' && s2[i] == '1')
        {
            swp2.push_back(i);
        }
    }
    p = 2 * p + 1;
    cout << p << endl;
    int pos = swp1.back();
    cout << pos << endl;
    swp1.pop_back();
    while(!swp1.empty() || !swp2.empty())
    {
        if(swp2.size())
        {
            cout << swp2.back() << endl;
            swp2.pop_back();
        }
        if(swp1.size())
        {
            cout << swp1.back() << endl;
            swp1.pop_back();
        }
    }
    cout << pos << endl;
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