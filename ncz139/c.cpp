#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    stack<int> stk;
    queue<int> qu;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    vector<int> b(1), c(1);
    while(q -- )
    {
        int ob;
        cin >> ob;
        if(ob == 1)
        {
            int x;
            cin >> x;
            qu.push(x);
            stk.push(x);
            continue;
        }
        b.push_back(qu.front());
        c.push_back(stk.top());
        qu.pop(), stk.pop();
    }
    if(a == b && a == c)
    {
        cout << "both" << endl;
        return;
    }
    if(a == b)
    {
        cout << "queue" << endl;
        return;
    }
    if(a == c)
    {
        cout << "stack" << endl;
        return;
    }
    cout << -1 << endl;
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