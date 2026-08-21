#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    string s;
    cin >> s;
    const char a[5] = {'a', 'e', 'i', 'o', 'u'};
    if(s.size() != 8)
    {
        cout << "Well-Being" << endl;
        return;
    }
    for(int i = 0; i < 8; i ++ )
    {
        if(i % 2)
        {
            for(int j = 0; j < 5; j ++ )
            {
                if(s[i] == a[j])
                {
                    cout << "Well-Being" << endl;
                    return;
                }
            }
        }
        else
        {
            int j;
            for(j = 0; j < 5; j ++ )
            {
                if(s[i] == a[j]) break;
            }
            if(j == 5)
            {
                cout << "Well-Being" << endl;
                return;
            }
        }
    }
    cout << "Suspected Virus" << endl;
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