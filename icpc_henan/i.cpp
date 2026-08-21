#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    string s;
    cin >> s;
    s = " " + s;
    int cnt = 0;
    int flag = 0;
    auto dfs = [&](auto self, int dep) -> void {
        if(cnt == 7)
        {
            flag = 1;
            return;
        }
        if(dep > 8)
        {
            return;
        }
        for(int i = 1; i <= 8; i ++ )
        {
            if(s[i] == '1')
            {
                dep ++;
                cnt ++;
                continue;
            }
            if(s[(i + 2) % 8 + 1] == '0' && s[(i + 4) % 8 + 1] == '0')
            {
                s[(i + 2) % 8 + 1] = '1';
                cnt ++;
                s[(i + 4) % 8 + 1] = '1';
                cnt ++;
                self(self, dep + 1);
                s[(i + 2) % 8 + 1] = '0';
                cnt --;
                s[(i + 4) % 8 + 1] = '0';
                cnt --;
            }
            if(s[(i + 2) % 8 + 1] == '0')
            {
                s[(i + 2) % 8 + 1] = '1';
                cnt ++;
                self(self, dep + 1);
                s[(i + 2) % 8 + 1] = '0';
                cnt --;
            }
            if(s[(i + 4) % 8 + 1] == '0')
            {
                s[(i + 4) % 8 + 1] = '1';
                cnt ++;
                self(self, dep + 1);
                s[(i + 4) % 8 + 1] = '0';
                cnt --;
            }
        }
    };
    dfs(dfs, 1);
    cout << (flag ? "Yes" : "No") << endl;
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