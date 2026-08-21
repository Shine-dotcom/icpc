#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int tr[100005], n, a[100005];
int lowbit(int x)
{
    return x & (-x);
}
void add(int x, int v)
{
    tr[x] += v;
    while(x <= n)
    {
        x += lowbit(x);
        tr[x] += v;
    }
}
int sum(int x)
{
    int sum = 0;
    while(x)
    {
        sum += tr[x];
        x -= lowbit(x);
    }
    return sum;
}
void solve()
{
    int n1, n2;
    cin >> n1 >> n2;
    n = n1 + n2;
    vector<pair<int, int>> sorted(n + 1);
    for(int i = n1; i >= 1; i -- )
    {
        add(i, 1);
        cin >> sorted[i].first;
        sorted[i].second = i;
    }
    for(int i = n1 + 1; i <= n; i ++ )
    {
        add(i, 1);
        cin >> sorted[i].first;
        sorted[i].second = i;
    }
    sort(sorted.begin() + 1, sorted.end());
    int ans = 0;
    sorted[0].second = n1;
    for(int i = n; i >= 1; i -- )
    {
        add(sorted[i].second, -1);
        if(i == n)
        {
            ans += abs(sum(sorted[i].second) - sum(sorted[0].second));
            continue;
        }
        ans += abs(sum(sorted[i].second) - sum(sorted[i + 1].second));
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