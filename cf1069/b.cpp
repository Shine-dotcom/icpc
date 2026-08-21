    #include<bits/stdc++.h>
    using namespace std;
    #define int long long
    #define endl '\n'
    void solve()
    {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n + 1);
        vector<int> b(n + 1);
        iota(b.begin(), b.end(), 0);
        // for(auto x : b) cout << x << ' ';
        // cout << endl;
        b[r] = l - 1;
        for(int i = 1; i <= n; i ++ )
        {
            a[i] = b[i] ^ b[i - 1];
        }
        for(int i = 1; i <= n; i ++ )
        {
            cout << a[i] << ' ';
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