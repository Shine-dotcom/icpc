#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < 26; i ++ )
    {
        for(int j = 0; j < 26; j ++ )
        {
            string s0 = "";
            s0.push_back(i + 'a');
            s0.push_back(j + 'a');
            int l = 0;
            bool flag = 0;
            for(int k = 0; k < s.size(); k ++ )
            {
                if(s[k] == s0[l]) l ++;
                if(l == 2)
                {
                    flag = 1;
                    break;
                }
            }
            if(!flag) continue;
            l = 0;
            for(int k = 0; k < t.size(); k ++ )
            {
                if(t[k] == s0[l]) l ++;
                if(l == 2)
                {
                    cout << s0 << endl;
                    return;
                }
            }
        }
    }
    cout << "HENG!" << endl;
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