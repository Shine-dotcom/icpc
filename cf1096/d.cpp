#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(2 * n + 1);
    int ans = 1;
    int idx1 = -1, idx2 = -1;
    for(int i = 1; i <= 2 * n; i ++ )
    {
        cin >> a[i];
        if(a[i] == 0)
        {
            if(idx1 == -1)
            {
                idx1 = i;
            }
            else
            {
                idx2 = i;
            }
        }
    }
    int res = 0;
    set<int> st;
    for(int i = idx1, j = idx1; i >= 1 && j <= 2 * n; i --, j ++ )
    {
        if(a[i] != a[j]) break;
        st.insert(a[i]);
    }
    for(auto x : st)
    {
        if(res == x)
        {
            res ++;
            continue;
        }
        break;
    }
    ans = max(ans, res);
    st.clear();
    for(int i = idx2, j = idx2; i >= 1 && j <= 2 * n; i --, j ++ )
    {
        if(a[i] != a[j]) break;
        st.insert(a[i]);
    }
    res = 0;
    for(auto x : st)
    {
        if(res == x)
        {
            res ++;
            continue;
        }
        break;
    }
    ans = max(res, ans);
    int tmp = idx1 + idx2;
    st.clear();
    for(int i = tmp / 2, j = (tmp + 1) / 2; i >= 1 && j <= 2 * n; i --, j ++ )
    {
        if(a[i] != a[j]) break;
        st.insert(a[i]);
    }
    res = 0;
    for(auto x : st)
    {
        if(res == x)
        {
            res ++;
            continue;
        }
        break;
    }
    ans = max(res, ans);
    cout << ans << endl;
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