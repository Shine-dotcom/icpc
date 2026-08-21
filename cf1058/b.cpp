#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> b(n);
    for(auto &x : b) cin >> x;
    vector<int> a;
    a.push_back(1);
    int tmp = 1;
    for(int i = 1; i < n; i ++ )
    {
        int ls = a.size();
        if(b[i] - b[i - 1] == ls + 1)
        {
            a.push_back(++ tmp);
            continue;
        }
        a.push_back(a[ls - b[i] + b[i - 1]]);
    }
    for(auto x : a) cout << x << ' ';
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