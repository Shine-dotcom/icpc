#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    stack<char> stk;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(auto c : s)
    {
        if(stk.empty() || !(stk.top() == '(' && c == ')'))
        stk.push(c);
        else
        stk.pop();
        // if(stk.empty())cout << endl;
        // else cout << stk.top() << endl;
    }
    // cout << -1 << endl;
    cout << stk.size() << endl;
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
    return 0;
}