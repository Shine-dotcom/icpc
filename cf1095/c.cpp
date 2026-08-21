#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve()
{
    int n;
    cin >> n;
    multiset<int> st;
    for(int i = 1; i <= n; i ++ )
    {
        int a;
        cin >> a;
        st.insert(a);
    }
    int l = 0, r = n;
    while(l < r)
    {
        int mid = (l + r + 1) / 2;
        assert(st.size() == n);

        bool flag = 1;
        vector<int> removed;
        for(int i = mid - 1; i >= 0; i -- )
        {
            if(st.count(i))
            {
                removed.push_back(i);
                st.erase(st.find(i));
                continue;
            }
            else
            {
                int x = *st.rbegin();
                if(x < 2 * i + 1)
                {
                    flag = 0;
                    break;
                }
                removed.push_back(x);
                st.erase(st.find(x));
            }
        }
        for(auto &x : removed) st.insert(x);
        if(flag) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
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