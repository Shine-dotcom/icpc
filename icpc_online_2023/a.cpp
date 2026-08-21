#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
queue<string> qa, qb;
vector<string> ans;
int n, m;
void solve()
{
    cin >> n >> m;
    set<string> st;
    for(int i = 1; i <= n; i ++ )
    {
        string s;
        cin >> s;
        if(st.find(s) != st.end()) continue;
        st.insert(s);
        qa.push(s);
    }
    st.clear();
    for(int i = 1; i <= m; i ++ )
    {
        string s;
        cin >> s;
        if(st.find(s) != st.end()) continue;
        st.insert(s);
        qb.push(s);
    }
    st.clear();
    while(qa.size() || qb.size())
    {
        if(qa.size())
        {
            string s = qa.front();
            // cout << s << endl;
            qa.pop();
            ans.push_back(s);
        }
        if(qb.size())
        {
            string s = qb.front();
            // cout << s << endl;
            qb.pop();
            ans.push_back(s);
        }
    }
    // cout << endl;
    for(auto x : ans)
    {
        if(st.find(x) != st.end()) continue;
        st.insert(x);
        cout << x << endl;
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
    return 0;
}