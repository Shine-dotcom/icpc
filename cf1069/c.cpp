    #include<bits/stdc++.h>
    using namespace std;
    #define int long long
    #define endl '\n'
    void solve()
    {
        string s, t;
        cin >> s >> t;
        vector<int> cnt(26);
        for(auto x : t)
        {
            cnt[x - 'a'] ++;
        }
        for(auto x : s)
        {
            if(cnt[x - 'a'] == 0)
            {
                cout << "Impossible" << endl;
                return;
            }
            cnt[x - 'a'] --;
        }
        int n = s.size();
        vector<int> pre(n + 1);
        vector<int> val;
        s = " " + s;
        for(int i = 1; i <= n; i ++ )
        {
            pre[i] = max(pre[i - 1], (int)s[i] - 'a');
        }
        for(int i = 0, j = 1; i < 26; i ++ )
        {
            while(j <= n && i >= pre[j])
            {
                val.push_back(s[j] - 'a');
                j ++;
            }
            while(cnt[i])
            {
                val.push_back(i);
                cnt[i] --;
            }
        }
        for(auto x : val)
        {
            cout << (char)(x + 'a');
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