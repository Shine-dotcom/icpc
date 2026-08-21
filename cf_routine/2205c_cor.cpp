#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int MAXV = 1e6 + 10;
const int INF = 1e7 + 5;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1);
    vector<int> vis(MAXV, 0);
    vector<bool> chg(n + 1, false);
    
    auto init = [&](vector<int>& now) {
        for (auto& v : now) {
            cin >> v;
            vis[v] = 0;          // 原代码中清空这些值的状态，可保留
        }
        reverse(now.begin(), now.end());
        vector<int> nw;
        for (auto v : now) {
            if (!vis[v]) {
                nw.push_back(v);
                vis[v] = 1;
            }
        }
        for (auto v : nw) vis[v] = 0;
        now = nw;
    };
    
    auto change = [&](vector<int>& now) {
        if (now.size() == 1 && now[0] == INF) return;
        vector<int> nw;
        for (auto v : now) {
            if (!vis[v]) nw.push_back(v);
        }
        now = nw;
    };
    
    for (int i = 1; i <= n; ++i) {
        int len;
        cin >> len;
        a[i].resize(len);
        init(a[i]);
    }
    
    for (int rd = 1; rd <= n; ++rd) {
        int id = -1;
        for (int j = 1; j <= n; ++j) {
            if (!chg[j]) {
                if (id == -1 || a[j] < a[id]) {
                    id = j;
                }
            }
        }
        for (auto v : a[id]) {
            cout << v << ' ';
            vis[v] = 1;
        }
        a[id] = {INF};
        chg[id] = true;
        for (int j = 1; j <= n; ++j) {
            if (!chg[j]) change(a[j]);
        }
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}