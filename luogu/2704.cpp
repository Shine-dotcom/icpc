#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 110, M = 1100;
int dp[N][M];
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> s[i];
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        int tmp = 0;
        string t = s[i];
        while(t.size())
        {
            a[i] += ((t[t.size() - 1] == 'H') << tmp);
            tmp ++;
            t.pop_back();
        }
    }
    // for(int i = 1; i <= n; i ++ ) cout << a[i] << ' ';
    // cout << endl;
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 0; j < (1 << m); j ++ )
        {
            if(a[i] & j) continue;
            if((j & (j << 1)) && (j & (j << 2))) continue;
            if(i >= 2)
            {
                for(int k = 0; k <= (1 << m); k ++ )
                {
                    if(j & k) continue;
                }
            }
            if(i >= 1)
            {
                for(int k = 0; )
            }
        }
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