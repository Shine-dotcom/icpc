#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    int ed = -1;
    vector<pair<int, int>> xj;
    while(m -- )
    {
        int a, b;
        cin >> a >> b;
        xj.push_back({a, b});
    }
    sort(xj.begin(), xj.end(), [&](pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    });
    int mn = 0, mx = 0;
    m = xj.size();
    int tmp2 = 1;
    int t = 0;
    for(int i = 0; i < m; i ++ )
    {
        if(tmp2 != xj[i].second)
        {
            mx += ((xj[i].first - t) % 2 ? xj[i].first - t : xj[i].first - t - 1);
            mn ++;
        }
        else
        {
            mx += ((xj[i].first - t) % 2 ? xj[i].first - t - 1 : xj[i].first - t);
        }
        t = xj[i].first;
        tmp2 = xj[i].second;
        if(t == n)
        {
            ed = xj[i].second;
        }
    }
    if(n > t)
    {
        mx += n - t;
    }
    int tt;
    cin >> tt;
    while(tt -- )
    {
        int x;
        cin >> x;
        if(x < mn || x > mx)
        {
            cout << "No" << endl;
            continue;
        }
        if(ed != -1 && x % 2 == ed)
        {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
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