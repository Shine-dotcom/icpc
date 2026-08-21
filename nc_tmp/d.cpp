#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    map<int, int> f;
    stack<int> stk;
    for(int i = 1; i <= n; i ++ )
    {
        int a;
        cin >> a;
        if(f[a])
        {
            while(stk.top() != a)
            {
                f[stk.top()] = 0;
                stk.pop();
            }
            stk.pop();
            f[a] = 0;
        }
        else
        {
            stk.push(a);
            f[a] = 1;
        }
    }
    cout << stk.size() << endl;
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