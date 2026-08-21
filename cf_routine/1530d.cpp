#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), flag(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        flag[a[i]] ++;
    }
    vector<int> v;
    int cnt = 0;
    vector<int> pos;
    for(int i = 1; i <= n; i ++ )
    {
        if(flag[i] == 0)
        {
            v.push_back(i);
        }
        else
        {
            if(flag[i] > 1)
            {
                pos.push_back(i);
            }
            cnt ++;
        }
    }
    reverse(v.begin(), v.end());
    int j = 0;
    for(int i = 1; i <= n; i ++ )
    {
        if(flag[a[i]] > 1 && j <= v.size())
        {
            if(i == v[j])
            {
                continue;
            }
            flag[a[i]] --;
            a[i] = v[j ++ ];
        }
    }
    cout << cnt << endl;
    for(int i = 1; i <= n; i ++ )
    {
        cout << a[i] << ' ';
    }
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