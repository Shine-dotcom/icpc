#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n;
struct Node{
    string s = "";
}tr[500010];
string S[100010];
void pushup(int p)
{
    tr[p].s = "";
    for(int i = 0; i < n; i ++ )
    {
        if(tr[p << 1].s[i] == '?' && tr[p << 1 | 1].s[i] == '?')
            tr[p].s.push_back('?');
        else if(tr[p << 1].s[i] == '?')
            tr[p].s.push_back(tr[p << 1 | 1].s[i]);
        else if(tr[p << 1 | 1].s[i] == '?')
            tr[p].s.push_back(tr[p << 1].s[i]);
        else if(tr[p << 1].s[i] == tr[p << 1 | 1].s[i])
            tr[p].s.push_back(tr[p << 1].s[i]);
        else
            tr[p].s.push_back('2');
    }
    // cout << p << ' ' << tr[p].s << endl;
}
void build(int l, int r, int p)
{
    if(l == r)
    {
        tr[p].s = S[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1 | 1);
    pushup(p);
}
void update(int pos, int s, int e, int p, string t)
{
    if(s == e)
    {
        tr[p].s = t;
        return;
    }
    int mid = (s + e) >> 1;
    if(pos <= mid) update(pos, s, mid, p << 1, t);
    else update(pos, mid + 1, e, p << 1 | 1, t);
    pushup(p);
}
string query(int l, int r, int p, int s, int e)
{
    if(l <= s && e <= r)
    {
        return tr[p].s;
    }
    int mid = (s + e) >> 1;
    string s1, s2, s0;
    if(l <= mid && r > mid) 
    {
        s1 = query(l, r, p << 1, s, mid);
        s2 = query(l, r, p << 1 | 1, mid + 1, e);
        for(int i = 0; i < n; i ++ )
        {
            if(s1[i] == '?' && s2[i] == '?')
                s0.push_back('?');
            else if(s1[i] == '?')
                s0.push_back(s2[i]);
            else if(s2[i] == '?')
                s0.push_back(s1[i]);
            else if(s1[i] == s2[i])
                s0.push_back(s1[i]);
            else
                s0.push_back('2');
        }
        return s0;
    }
    if(l <= mid) return query(l, r, p << 1, s, mid);
    if(r > mid) return query(l, r, p << 1 | 1, mid + 1, e);
}
void solve()
{
    int m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i ++ )
        cin >> S[i];
    build(1, m, 1);
    // for(int i = 1; i <= 2 * m + 1; i ++ )
    // {
    //     cout << i << ' ' << tr[i].s << endl;
    // }
    int ans = 0;
    while(q -- )
    {
        int op, l;
        cin >> op >> l;
        if(op == 0)
        {
            int r;
            cin >> r;
            string s = query(l, r, 1, 1, m);
            // cout << s << endl;
            int cnt = 0;
            int flag = 0;
            for(int i = 0; i < n; i ++ )
            {
                if(s[i] == '2')
                {
                    flag = 1;
                    break;
                }
                if(s[i] == '?')
                {
                    cnt ++;
                }
            }
            // cout << (1 << cnt) << endl;
            if(!flag) ans ^= (1 << cnt);
            cnt = 0;
        }
        if(op == 1)
        {
            string t;
            cin >> t;
            update(l, 1, n, 1, t);
        }
    }
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
}