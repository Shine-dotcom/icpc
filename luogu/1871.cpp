#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> st(n + 1), prime(n + 1), query_p(n + 1);
    int cnt = 0;
    for(int i = 2; i <= n; i ++ )
    {
        if(st[i] == 0) prime[cnt ++ ] = i;
        for(int j = 0; prime[j] <= n / i; j ++ )
        {
            st[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    vector<pair<char, int>> a(m + 1);
    for(int i = 1; i <= m; i ++ )
    {
        char c;
        int id;
        cin >> c >> id;
        a[i] = {c, id};
    }
    for(int i = 1; i <= m; i ++ )
    {
        vector<int> tmp;
        int t = a[i].second;
        if(a[i].first == '+')
        {
            int flag = 0;
            if(query_p[a[i].second] == -1 || query_p[a[i].second] == a[i].second)
            {
                cout << "Already on" << endl;
                continue;
            }
            if(a[i].second == 1)
            {
                st[t] = 1;
                query_p[t] = 1;
            }
            while(t != 1)
            {
                for(int j = 0; j < cnt; j ++ )
                {
                    if(t % prime[j] == 0)
                    {
                        tmp.push_back(prime[j]);
                        t /= prime[j];
                        break;
                    }
                }
            }
            for(auto u : tmp)
            {
                if(st[u])
                {
                    flag = 1;
                    cout << "Conflict with " << query_p[u] << endl;
                    break;
                }
            }
            if(!flag)
            {
                cout << "Success" << endl;
                st[a[i].second] = 1;
                for(auto u : tmp)
                {
                    st[u] = 1;
                    query_p[u] = a[i].second;
                }
                if(tmp.size() != 1)
                {
                    query_p[a[i].second] = -1;
                }
            }
        }
        else
        {
            if(query_p[a[i].second])
            {
                cout << "Success" << endl;
                int t = a[i].second;
                st[t] = 0, query_p[t] = 0;
                for(int j = 0; j < cnt; j ++ )
                {
                    if(t % prime[j] == 0)
                    {
                        st[prime[j]] = 0;
                        query_p[prime[j]] = 0;
                    }
                }
            }
            else
            {
                cout << "Already off" << endl;
            }
        }
        // cout << i << ": " << endl;
        // cout << "tmp: ";
        // for(auto u : tmp)
        // {
        //     cout << u << ' ';
        // }
        // cout << endl;
        // cout << "query_p: ";
        // for(auto u : query_p)
        // {
        //     cout << u << ' ';
        // }
        // cout << endl;
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



// 未解决 https://www.luogu.com.cn/problem/P1871
