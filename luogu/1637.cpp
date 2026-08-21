#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int maxn = 3e4 + 10;
int n, m;
int c1[maxn], c2[maxn];
int A[maxn], _A[maxn];
int Lef[maxn], Rit[maxn];

int _Q(int val)
{
    return lower_bound(_A + 1, _A + m + 1, val) - _A;
}
int lowbit(int i)
{
    return i & (-i);
}
void add(int *C, int pos, int val)
{
    while(pos <= maxn)
    {
        C[pos] += val;
        pos += lowbit(pos); // ?
    }
}
int sum(int *C, int pos)
{
    int res = 0;
    while(pos > 0)
    {
        res += C[pos];
        pos -= lowbit(pos); // ?
    }
    return res;
}
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> A[i];
        _A[i] = A[i];
    }
    sort(_A + 1, _A + n + 1);
    m = unique(_A + 1, _A + n + 1) - (_A + 1);
    for(int i = 1; i <= n; i ++ )
    {
        add(c1, _Q(A[i]), 1);
        Lef[i] = sum(c1, _Q(A[i]) - 1);
    }
    for(int i = n; i >= 1; i -- )
    {
        add(c2, _Q(A[i]), 1);
        Rit[i] = n - i - (sum(c2, _Q(A[i])) - 1);
    } // ?
    int ans = 0;
    for(int i = 2; i <= n; i ++ ) ans += Lef[i] * Rit[i];
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