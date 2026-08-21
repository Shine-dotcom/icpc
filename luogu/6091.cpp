#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int phi[1000010], st[1000010], prime[1000010];
int flag[1000010], root[1000010];
vector<vector<int>> pn(1000010);
void shai()
{
    flag[1] = 1;
    flag[2] = 1;
    flag[4] = 1;
    for(int i = 1; prime[i]; i ++ )
    {
        int t = prime[i];
        while(t <= 1e6 + 5)
        {
            flag[t] = 1;
            root[t] = prime[i];
            t *= prime[i];
        }
        t = 2;
        while(t <= 1e6 + 5)
        {
            flag[t] = 1;
            root[t] = prime[i];
            t *= prime[i];
        }
    }
}
void init()
{
    for(int i = 2; i <= 1000005; i ++ )
    {
        if(pn[i].empty())
        {
            for(int j = i; j <= 1000005; j += i)
            {
                pn[j].push_back(i);
            }
        }
    }
}
void euler()
{
    phi[1] = 1;
    int cnt = 0;
    for(int i = 2; i <= 1000010; i ++ )
    {
        if(!st[i])
        {
            prime[cnt ++ ] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; prime[j] <= 1000010 / i; j ++ )
        {
            st[prime[j] * i] = 1;
            if(i % prime[j] == 0)
            {
                phi[i * prime[j]] = prime[j] * phi[i];
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}
int ksm(int a, int b, int mod)
{
    int ans = 1;
    while(b)
    {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    int n, d;
    cin >> n >> d;
    vector<int> roots;
    if(flag[n] == 0)
    {
        cout << 0 << endl;
        cout << endl;
        return;
    }
    int min_root;
    for(int i = 1; i < n; i ++ )
    {
        if(__gcd(i, n) != 1) continue;
        int flag = 1;
        for(auto fac : pn[phi[n]])
        {
            if(ksm(i, phi[n] / fac, n) == 1)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            min_root = i;
            break;
        }
    }
    roots.push_back(min_root);
    for(int i = 2; i < phi[n]; i ++ )
    {
        if(__gcd(i, phi[n]) == 1)
        {
            roots.push_back(ksm(min_root, i, n));
        }
    }
    sort(roots.begin(), roots.end());
    cout << roots.size() << endl;
    for(int i = 1; i <= roots.size() / d; i ++ )
    {
        if(i * d - 1 < roots.size())
        cout << roots[i * d - 1] << ' ';
    }
    cout << endl;
    return;
    // for(int i = 1; i <= 30; i ++ )
    // {
    //     cout << phi[i] << ' ';
    // }
    // cout << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    euler();
    shai();
    init();
    while(t -- )
    {
        solve();
    }
}
