#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, V, ans, head, tail, q[40010], q2[40010], dp[40010];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> V;
    for(int i = 1; i <= n; i ++ )
    {
        int v, w, c;
        cin >> w >> v >> c;
        if(v == 0)
        {
            ans += w * c;
            continue;
        }
        int k = V / v;
        c = min(c, k);
        for(int d = 0; d < v; d ++ )
        {
            head = tail = 0;
            k = (V - d) / v;
            for(int j = 0; j <= k; j ++ )
            {
                while(head < tail && dp[d + j * v] - j * w >= q2[tail - 1])
                    tail --;
                q[tail] = j;
                q2[tail ++ ] = dp[d + j * v] - j * w;
                while(head < tail && q[head] < j - c)
                    ++ head;
                dp[d + j * v] = max(dp[d + j * v], q2[head] + j * w);
            }
        }
    }
    cout << ans + dp[V] << endl;
    return 0;
}