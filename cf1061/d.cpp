#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
#define int long long
void solve()
{
    int n;
    cin >> n;
    int cnto = n / 2 + n % 2;
    int cnte = n / 2;
    vector<int> ans;
    queue<int> q;
    for(int i = 1; i < n; i ++ )
    {
        q.push(i);
    }
    int t = n;
    int cntn = 0;
    while(t)
    {
        cntn ++;
        t >>= 1;
    }
    while(ans.size() < cntn)
    {
        cout << "cnto: " << cnto << endl;
        cout << "cnte: " << cnte << endl;
        int ls = ans.size();
        int odd = 0, even = 0;
        vector<pair<int, int>> tmp;
        vector<int> o, e;
        while(q.size())
        {
            cout << "? " << q.front() << ' ' << (1 << ls) << endl;
            int x;
            cin >> x;
            tmp.push_back({x, q.front()});
            q.pop();
        }
        for(auto x : tmp)
        {
            cout << x.first << ' ' << x.second << endl;
        }
        cout << endl;
        for(auto x : tmp)
        {
            if(x.first == 1)
            {
                odd ++;
                o.push_back(x.second);
                continue;
            }
            even ++;
            e.push_back(x.second);
        }
        int t = odd + 1;
        if(odd == cnto - 1)
        {
            ans.push_back(1);
            cnte = t / 2;
            cnto = t / 2 + t % 2;
            for(auto x : o)
            {
                q.push(x);
            }
        }
        else
        {
            t = even + 1;
            ans.push_back(0);
            cnto = t / 2 + t % 2;
            cnte = t / 2;
            for(auto x : e)
            {
                q.push(x);
            }
        }
    }
    // for(auto x : ans)
    // cout << x << ' ';
    // cout << endl;
    int base = 1, res = 0;
    for(auto x : ans)
    {
        res += x * base;
        base <<= 1;
    }
    cout << "! " << res << endl;
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