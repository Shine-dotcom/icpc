#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e6 + 10;
int f[N];
int find(int x)
{
    return (f[x] == x ? x : f[x] = find(f[x]));
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ )
    {
        f[i] = i;
    }
    int ans = 0;
    for(int i = 1; i <= m; i ++ )
    {
        int x, y;
        cin >> x >> y;
        if(find(x) != find(y))
        {
            f[find(x)] = find(y);
        }
        else
        {
            // cout << 111 << endl;
            ans ++;
        }
    }
    set<int> st;
    for(int i = 1; i <= n; i ++ )
    {
        st.insert(find(i));
    }
    ans += st.size() - 1;
    cout << ans << endl;
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
    return 0;
}