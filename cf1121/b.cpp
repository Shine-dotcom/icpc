#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    // if(n == 1)
    // {
    //     cout << a[1] << endl;
    //     return;
    // }
    // int mx = -1e9;
    // int idx = 0;
    // for(int i = m; i <= n; i ++ )
    // {
    //     if(mx <= a[i])
    //     {
    //         mx = a[i];
    //         idx = i;
    //     }
    // }
    // // cout << idx << endl;
    // sort(a.begin() + 1, a.begin() + idx);
    // int ans = 0;
    // for(int i = 1; i < m; i ++ )
    // {
    //     ans -= a[i];
    //     // cout << a[i] << ' ';
    // }
    // // cout << endl;
    // ans += a[idx] * m;
    // cout << ans << endl;
    /*
    新做法思路：通过枚举每一个可能的b[m]，然后用优先队列（堆）去处理剩下的值
    最后把处理出来的所有可能答案取个最大即可
    优化了时间复杂度，把重复的操作优化了
    */
    int ans = -1e18;
    int sum = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    for(int i = 1; i < m; i ++ )
    {
        sum += a[i];
        pq.push(a[i]);
    }
    for(int i = m; i <= n; i ++ )
    {
        int res = m * a[i] - sum;
        pq.push(a[i]);
        sum += a[i];
        sum -= pq.top();
        pq.pop();
        ans = max(ans, res);
    }
    cout << ans << endl;
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