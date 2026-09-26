#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node {
    int idx, ln = -1, rn = -1, w;
    string bin = "";
    bool operator > (const node &u) const {
        return w > u.w;
    }
};
void solve()
{
    int n;
    cin >> n;
    int cnt = n;
    priority_queue<node, vector<node>, greater<node>> pq;
    vector<string> arr(n + 1);
    vector<node> tree(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        string s;
        int w;
        cin >> s >> w;
        tree[i].w = w;
        tree[i].idx = i;
        arr[i] = s;
        pq.push(tree[i]);
    }
    if(n == 1)
    {
        cout << arr[1] << ' ' << 1 << endl;
        return;
    }
    while(pq.size() > 1)
    {
        node l = pq.top();
        pq.pop();
        node r = pq.top();
        pq.pop();
        tree.push_back({++ cnt, l.idx, r.idx, l.w + r.w, ""});
        pq.push(tree[cnt]);
    }
    int root = pq.top().idx;
    string bin = "";
    auto dfs = [&](auto self, int i) -> void {
        if(tree[i].ln == -1 && tree[i].rn == -1)
        {
            tree[i].bin = bin;
            return;
        }
        if(tree[i].ln != -1)
        {
            bin.push_back('0');
            self(self, tree[i].ln);
        }
        bin.pop_back();
        if(tree[i].rn != -1)
        {
            bin.push_back('1');
            self(self, tree[i].rn);
        }
        bin.pop_back();
    };
    dfs(dfs, root);
    for(int i = 1; i <= n; i ++ )
    {
        cout << arr[i] << ' ' << tree[i].bin << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t -- )
    {
        solve();
    }
    return 0;
}