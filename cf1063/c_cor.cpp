```
// nifeshe

#ifdef LOCAL
    #include <bits/include_all.h>
#else
    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
#endif

#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long

using namespace std;
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> inline bool umin(T &a, const T &b) { if(a > b) { a = b; return 1; } return 0; }
template <typename T> inline bool umax(T &a, const T &b) { if(a < b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll mod = 998244353;
const ll inf = 1e18;
const int MAX = 2e5 + 42;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<ll> dis(1, inf);

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for(auto &i : a) {
        for(auto &j : i) {
            cin >> j;
        }
    }

    vector<vector<pii>> pos(2 * n + 1);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            pos[a[i][j]].push_back({i, j});
        }
    }


    array<set<int>, 2> st;
    st[0].insert(inf);
    st[1].insert(-inf);
    for(int i = 0; i < n; i++) st[0].insert(i);
    for(int i = 0; i < n; i++) st[1].insert(i);

    auto add = [&](int x) {
        for(auto [i, j] : pos[x]) {
            st[i].erase(j);
        }
    };

    auto del = [&](int x) {
        for(auto [i, j] : pos[x]) {
            st[i].insert(j);
        }
    };

    auto check = [&]() {
        if(st[0].count(0)) return false;
        if(st[1].count(n - 1)) return false;
        if(*st[0].begin() - 1 <= *st[1].rbegin()) return false;

        return true;
    };

    int ans = 0;
    int r = 0;
    for(int l = 1; l <= 2 * n; l++) {
        while(r + 1 <= 2 * n && !check()) {
            add(++r);
        }
        if(!check()) break;

        ans += 2 * n - r + 1;
        del(l);
    }

    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ttt = 1;
    cin >> ttt;
    while(ttt--) {
        solve();
    }
}```