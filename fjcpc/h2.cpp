#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    int moda = n % 3;
    int num = (n + 9) / 10;
    int ga = m % 3, gt = m % 6;
    int ansa = (ga >= moda);
    if(moda == 0) ansa = 0;
    int anst = 0;
    ansa += m / 3;
    anst = min(num, m / 6);
    if(n == 11 && m >= 6) anst = 1;
    cout << ansa << ' ' << anst << endl;
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