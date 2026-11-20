#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a, b, c, m;
const int N = 1e6 + 10;
struct hurt {
    int lat, lbt, lct, rat, rbt, rct, ht;
}h[N];
int d[N], w[N];
int idx(int i, int j, int k) {return ((i - 1) * b + (j - 1)) * c + k;}
bool check(int x) {
    for(int i = 1; i <= a * b * c; i ++ )
    {
        d[i] = 0;
    }
    for(int i = 1; i <= x; i ++ )
    {
        int i1 = h[i].lat, j1 = h[i].lbt, k1 = h[i].lct;
        int i2 = h[i].rat, j2 = h[i].rbt, k2 = h[i].rct;
        int ht = h[i].ht;
        d[idx(i1, j1, k1)] += ht;
        d[idx(i2 + 1, j1, k1)] -= ht;
        d[idx(i1, j2 + 1, k1)] -= ht;
        d[idx(i1, j1, k2 + 1)] -= ht;
        d[idx(i2 + 1, j2 + 1, k1)] += ht;
        d[idx(i2 + 1, j1, k2 + 1)] += ht;
        d[idx(i1, j2 + 1, k2 + 1)] += ht;
        d[idx(i2 + 1, j2 + 1, k2 + 1)] -= ht;
    }
    for(int i = 1; i <= a; i ++ )
    {
        for(int j = 1; j <= b; j ++ )
        {
            for(int k = 1; k <= c; k ++ )
            {
                d[idx(i, j, k)] += d[idx(i - 1, j, k)];
            }
        }
    }
    for(int i = 1; i <= a; i ++ )
    {
        for(int j = 1; j <= b; j ++ )
        {
            for(int k = 1; k <= c; k ++ )
            {
                d[idx(i, j, k)] += d[idx(i, j - 1, k)];
            }
        }
    }
    for(int i = 1; i <= a; i ++ )
    {
        for(int j = 1; j <= b; j ++ )
        {
            for(int k = 1; k <= c; k ++ )
            {
                d[idx(i, j, k)] += d[idx(i, j, k - 1)];
                if(d[idx(i, j, k)] > w[idx(i, j, k)])
                    return true;
                // cout << d[idx(i, j, k)] << ' ';
            }
            // cout << endl;
        }
        // cout << endl;
    }
    return false;
}
void solve()
{
    cin >> a >> b >> c >> m;
    for(int i = 1; i <= a; i ++ )
    {
        for(int j = 1; j <= b; j ++ )
        {
            for(int k = 1; k <= c; k ++ )
            {
                cin >> w[idx(i, j, k)];
            }
        }
    }
    for(int i = 1; i <= m; i ++ )
    {
        cin >> h[i].lat >> h[i].rat >> h[i].lbt >> h[i].rbt >> h[i].lct >> h[i].rct >> h[i].ht;
    }
    int l = 1, r = m;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(check(mid))
        {
            r = mid;
        }
        else l = mid + 1;
        // cout << check(l) << ' ' << check(r) << endl;
    }
    cout << l << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t -- ) solve();
    return 0;
}