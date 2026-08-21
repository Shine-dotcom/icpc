#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    string s;
    cin >> s;
    if(s == "*")
    {
        cout << 1 << endl;
        return;
    }
    // cout << s.find("**") << endl;
    if(s.find("**") != string::npos)
    {
        cout << -1 << endl;
        return;
    }
    if(s.find("*<") != string::npos)
    {
        cout << -1 << endl;
        return;
    }
    if(s.find(">*") != string::npos)
    {
        cout << -1 << endl;
        return;
    }
    if(s.find("><") != string::npos)
    {
        cout << -1 << endl;
        return;
    }
    int len1 = 0, len2 = 0;
    int flag = 0;
    for(int i = 0; i < s.size(); i ++ )
    {
        if(i >= 1 && i < s.size() - 1 && s[i - 1] == '<' && s[i] == '*' && s[i + 1] == '>')
        {
            flag = 1;
            continue;
        }
        if(i >= 1 && s[i - 1] == '<' && s[i] == '>')
        {
            flag = 2;
        }
        cout << s[i] << ' ' << flag << endl;
        if(!flag)
        {
            len1 ++;
            continue;
        }
        len2 ++;
    }
    cout << max(len1, len2) + (flag == 1) << endl;
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