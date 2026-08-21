#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve() {
    int n; cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    s = " " + s;
    for(int i = 1; i <= n; i ++ ) {
        if(s[i] == '0') cnt ++;
        if(s[i] == '1') {
            if(cnt == 1) {
                cout << "NO" << endl;
                return;
            }
            cnt = 0;
        }
    }
    vector<int> res(n + 1);
    for(int i = 1; i <= n; i ++ ) {
        res[i] = i;
    }
    int l = 1;
    for(int i = 1; i <= n; i ++ ) {
        if(s[i] == '1') {
            for(int j = l, k = i - 1; j < k; j ++ , k -- ) {
                swap(res[j], res[k]);
            }
            l = i + 1;
        }
    }
    for(int j = l, k = n; j < k; j ++ , k -- ) {
        swap(res[j], res[k]);
    }
    cout << "YES" << endl;
    for(int i = 1; i <= n; i ++ ) {
        cout << res[i] << ' ';
    }
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t -- ) {
        solve();
    }
}