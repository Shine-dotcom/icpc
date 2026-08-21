#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
bool as[10000010];
vector<int> prime;
void init()
{
    for(int i = 2; i <= 1e7; i ++ )
    {
        if(as[i] == 0)
        {
            prime.push_back(i);
            for(int j = 2 * i; j <= 1e7; j += i)
            {
                as[j] = 1;
            }
        }
    }
}
void solve()
{
    int a, b;
    cin >> a >> b;
    if(b == a)
    {
        cout << 0 << endl;
        return;
    }
    if(b % a == 0)
    {
        cout << b << endl;
        return;
    }
    if(__gcd(a, b) != 1)
    {
        cout << min(a + b, a * b / __gcd(a, b)) << endl;
        return;
    }
    if(!as[a] && !as[b])
    {
        // cout << 333 << endl;
        cout << min(a * b, 2 * (a + b)) << endl;
        return;
    }
    // cout << 444 << endl;
    int res = a * b;
    int a0 = -1, b0 = -1;
    for(auto x : prime)
    {
        if(b % x == 0)
        {
            b0 = x;
            break;
        }
    }
    for(auto x : prime)
    {
        if(a % x == 0)
        {
            a0 = x;
            break;
        }
    }
    // cout << a0 << ' ' << b0 << endl;
    res = min(res, a * b0 + b);
    res = min(res, b * a0 + a);
    res = min(res, a + b + a0 * b0);
    res = min(res, a + b + 2 * (a0 + b0));
    res = min(res, 2 * (a + b));
    cout << res << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while(t -- )
    {
        solve();
    }
    return 0;
}