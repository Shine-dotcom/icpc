#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> cnt(n);
    for(int i = 0; i < n; i ++ )
    {
        int a; cin >> a;
        cnt[i] = a;
    }
    int ans = -1;

    for(int i = 0; i <= 3; i ++ )
    {
        
        for(int j = 0; j <= 3; j ++ )
        {   int sum = 0;
            for(int k = 0; k < n; k++){
                sum += (cnt[k] + i + j ) % 4;
            }
        
            if( sum % 4 == j){
            int res = i + sum;
            if(ans == -1 || res < ans)
            ans = res;
            }
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
    return 0;
}