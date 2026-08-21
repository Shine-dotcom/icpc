#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<string> s(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    vector<pair<int, int>> coor;
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= n; j ++ )
        {
            if(s[i][j] == '#')
            {
                coor.push_back({i, j});
            }
        }
    }
    if(coor.size() == 4)
    {
        if(coor[0].first == coor[1].first && coor[0].second == coor[1].second - 1)
        {
            if(coor[0].first == coor[2].first - 1 && coor[0].second == coor[2].second)
            {
                if(coor[0].first == coor[3].first - 1 && coor[0].second == coor[3].second - 1)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    vector<int> a1, a2;
    for(int i = 2; i <= 2 * n; i ++ )
    {
        for(int j = max(1ll, i - n); i - j >= 1 && j <= n; j ++ )
        {
            // cout << i - j << endl;
            // cout << j << endl;
            if(s[j][i - j] == '#')
            {
                a1.push_back(i);
                break;
            }
        }
    }
    if(a1.size() < 2)
    {
        cout << "YES" << endl;
        return;
    }
    if(a1.size() == 2 && abs(a1[1] - a1[0]) <= 1)
    {
        cout << "YES" << endl;
        return;
    }
    for(int i = 1 - n; i <= n - 1; i ++ )
    {
        for(int j = max(1 - i, 1ll); i + j <= n && j <= n; j ++ )
        {
            // cout << i + j << endl;
            if(s[j][i + j] == '#')
            {
                a2.push_back(i);
                break;
            }
        }
    }
    if(a2.size() < 2)
    {
        cout << "YES" << endl;
        return;
    }
    if(a2.size() == 2 && abs(a2[1] - a2[0]) <= 1)
    {
        cout << "YES" << endl;
        return;
    }
    
    cout << "NO" << endl;
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