#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int a;
    cin >> a;
    vector<int> bit(31);
    int cnt = 0;
    int t = a;
    while(t)
    {
        bit.push_back((t & 1));
        cnt += (t & 1);
        t >>= 1;
    }
    if(cnt % 2)
    {
        cout << "NO" << endl;
        return;
    }
    int ls = bit.size();
    int flag = 1;
    int flag2 = 0, cnt2 = 0;
    for(int i = 0; i < ls; i ++ )
    {
        if(bit[i] == 0 && flag2 == 0)
        {
            cnt2 ++;
            continue;
        }
        flag2 = 1;
        if(bit[i] != bit[ls - 1 - i + cnt2])
        {
            flag = 0;
            break;
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
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