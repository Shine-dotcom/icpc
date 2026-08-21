#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    string s;
    cin >> s;
    s = "0" + s;
    int n = s.size();
    int flag = 0;
    for(int i = 1; i < n; i ++ )
    {
        if(s[i] - '0' >= 5 && flag == 0)
        {
            flag = 1;
            s[i] = '0';
            s[i - 1] += 1;
            if(s[i - 1] - '0' == 10)
            {
                int j = i - 1;
                while(s[j] - '0' == 10 && j >= 1)
                {
                    s[j - 1] += 1;
                    s[j] = '0';
                    j --;
                }
            }
            continue;
        }
        if(flag == 1)
        {
            s[i] = '0';
        }
    }
    if(s[n - 1] != '0')
        s[n - 1] = '0';
    if(s[0] == '1') cout << s[0];
    for(int i = 1; i < n; i ++ )
    {
        cout << s[i];
    }
    cout << endl;
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