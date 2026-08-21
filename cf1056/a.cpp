#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    int cnt = 0;
    int win, lose = 0;
    win = n;
    while(win > 1 || lose > 1)
    {
        // win = (win + 1) / 2;
        cnt += lose / 2;
        lose = (lose + 1) / 2;
        lose += win / 2;
        cnt += win / 2;
        win = (win + 1) / 2;
        // cout << win << ' ' << lose << endl;
    }
    cout << cnt + 1 << endl;
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
}