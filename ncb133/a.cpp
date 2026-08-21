#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e5 + 10;
int r[8], a[N];
int f(int rating)
{
    if(rating >= 0 && rating <= 699) return 1;
    if(rating >= 700 && rating <= 1099) return 2;
    if(rating >= 1100 && rating < 1500) return 3;
    if(rating >= 1500 && rating < 2000) return 4;
    if(rating >= 2000 && rating < 2400) return 5;
    if(rating >= 2400 && rating <= 2799) return 6;
    return 7;
}
void solve()
{
    int n;
    cin >> n;
    int init = 1000;
    for(int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        init += x;
        r[f(init)] ++;
    }
    for(int i = 1; i <= 7; i ++ )
    {
        cout << r[i] << ' ';
    }
    cout << endl;
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