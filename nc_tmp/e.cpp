#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int a, b, l, r;
    cin >> a >> b >> l >> r;
    vector<int> tmp;
    int t = b - a;
    int cnt = 0;
    for(int i = 1; i <= sqrt(t); i ++ )
    {
        if(i * i == t)
        {
            tmp.push_back(i);
            continue;
        }
        if(t % i == 0)
        {
            tmp.push_back(i);
            tmp.push_back(t / i);
        }
    }
    for(auto x : tmp)
    {
        if(l <= x + b && x + b <= r)
        {
            cnt ++;
        }
    }
    cout << cnt << endl;
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