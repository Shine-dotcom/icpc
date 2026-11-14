/*
今日算法：ST表
created 2026/11/13 15:20
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e5 + 10;
int a[N], dp[N][20];
/*
dp[i][j]表示从第i个数开始，区间长度为(1 << j)的区间
*/
void solve()
{
    // 初始化
    for(int i = 0; i < N; i ++ )
    {
        a[i] = 0;
        for(int j = 0; j < 20; j ++ )
        {
            dp[i][j] = 0;
        }
    }
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) cin >> a[i], dp[i][0] = a[i]; // 根据定义，dp[i][0] 就是i这个数
    int k = log2(n);
    for(int i = 1; i <= k; i ++ )
    {
        for(int j = 1; j + (1 << (i - 1)) <= n; j ++ )
        {
            dp[j][i] = max(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]); 
            /*
            1. 循环特点
            必须以区间长度为外循环，否则状态尚未计算就会被转移（类似的还有区间dp）
            2. 方程解释
            我把一个区间砍成两半，前一半的最大值跟后一半的最大值取最大，就是当前的最大值
            */
        }
    }
    while(m -- )
    {
        int l, r;
        cin >> l >> r;
        int s = log2(r - l + 1);
        cout << max(dp[l][s], dp[r - (1 << s) + 1][s]) << endl; // s下取整的结果一定大于等于区间长度的一半
    }
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