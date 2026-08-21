#include<bits/stdc++.h>
#include<ext/rope>
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define eb emplace_back
#define fi first
#define se second
#define lowbit(x) ((x)&-(x))
#define int long long
using namespace std;
using namespace __gnu_cxx;
using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int N = 1e6 + 10;
const int INF = 0x3f3f3f3f;
const ll inf = 0x3f3f3f3f3f3f3f3f;

const int mod = 998244353;
int inv[N], fac[N];
int fp(int a,int n)
{
    int ans = 1;
    a %= mod;
    while (n)
    {
        if (n & 1)ans = (ans * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans;
}
int C(int n, int m)
{
    if (n == m)return 1;
    return fac[n] % mod * inv[m] % mod * inv[n - m] % mod;
}
int A(int n, int m)
{
    if (n == 0 || m == 0)return 1;
    return C(n, m) * fac[m] % mod;
}

void init(int n)
{
    fac[0] = 1;
    for (int i = 1;i <= n;i++)
    {
        fac[i] = (fac[i - 1] * i) % mod;
        inv[i] = fp(fac[i], mod - 2);
        // cout << fac[i] << ' ';
    }
}

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    int a, b;
    init(n+1);
    if (n % 2 == 0)
    {
        a = b = n / 2;
    }
    else
    {
        a = n / 2 + 1;
        b = n / 2;
    }
    int ta = 0, tb = 0;
    for (int i = 0;i < n;i++)
    {
        if (s[i] == 'j')ta++;
        if (s[i] == 'o')tb++;
    }
    // cout << ta << ' ' << tb << '\n';
    if (a < ta || b < tb)
    {
        cout << 0 << '\n';
        return;
    }
    // cout << A(a, ta) << '\n';
    // cout << A(b, tb) << '\n';
    int ans = A(a, ta) % mod * A(b, tb) % mod * A(n - ta - tb, n - ta - tb) % mod;
    cout << ans << '\n';


}



signed main()
{
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T; T = 1;
    //cin>>T;
    while(T--){solve();}
}
