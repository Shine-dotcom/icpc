#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<string> a1(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a1[i];
    }
    vector<string> a2(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        if(a1[i].size() == 1)
        {
            a2[i] = "";
            continue;
        }
        bool flag = 0;
        for(int j = 0; j < a1[i].size(); j ++ )
        {
            if(j == a1[i].size() - 1 && flag == 0)
            {
                continue;
            }
            else if(flag == 0 && a1[i][j] > a1[i][j + 1])
            {
                flag = 1;
                continue;
            }
            a2[i].push_back(a1[i][j]);
        }        
    }
    sort(a2.begin() + 1, a2.end());
    for(int i = 1; i <= n; i ++ )
    {
        cout << a2[i];
    }
    cout << endl;
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