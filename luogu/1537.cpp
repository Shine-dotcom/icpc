#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e4 + 10;
bool dp[6 * N];
void solve()
{
    int id = 0;
    while(1)
    {
        int sum = 0;
        vector<int> a(7);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= 6; i ++ ) cin >> a[i], sum += i * a[i];
        if(sum == 0)
        {
            break;
        }
        if(sum % 2)
        {
            cout << "Collection #" << ++ id << ":" << endl;
            cout << "Can't be divided." << endl;
            cout << endl;
            continue;
        }
        int m = sum / 2;
        dp[0] = 1;
        for(int i = 1; i <= 6; i ++ )
        {
            vector<int> v;
            int fac = 1;
            for(int j = 0; j <= 12; j ++ )
            {
                if(fac > a[i])
                {
                    v.push_back(a[i]);
                    break;
                }
                else
                {
                    v.push_back(fac);
                    a[i] -= fac;
                }
                fac <<= 1;
            }
            // cout << i << endl;
            // for(auto x : v)
            // {
            //     cout << x << ' ';
            // }
            // cout << endl;
            for(int j = 0; j <= v.size(); j ++ )
            {
                for(int k = sum; k >= v[j]; k -- )
                {
                    dp[k] |= dp[k - i * v[j]];
                }
            }
        }
        if(dp[m])
        {
            cout << "Collection #" << ++ id << ":" << endl;
            cout << "Can be divided." << endl;
            cout << endl;
        }
        else
        {
            cout << "Collection #" << ++ id << ":" << endl;
            cout << "Can't be divided." << endl;
            cout << endl;
        }
    }
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