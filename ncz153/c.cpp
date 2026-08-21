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
    p *= 3;
    cout << p << endl;
    while(!swp1.empty() && !swp2.empty())
    {
        cout << swp1.back() << endl;
        cout << swp2.back() << endl;
        cout << swp1.back() << endl;
        swp1.pop_back();
        swp2.pop_back();
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
}