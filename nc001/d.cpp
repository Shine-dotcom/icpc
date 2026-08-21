#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;
struct node{
    int fa, r, l;
};
void solve()
{
    int n;
    cin >> n;
    vector<int> tr(n + 1, -1);
    int cnt = 0;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> tr[i];
        if(tr[i] != -1)
        {
            cnt ++;
        }
    }
    cout << "The size of the tree is " << cnt << endl;
    cout << "Node " << tr[1] << " is the root node of the tree" << endl;
    vector<node> a(cnt + 1);
    auto dfs = [&](auto self, int x) -> void{
        if(x > n || tr[x] == -1) return;
        a[tr[x]].fa = tr[x / 2];
        if(x * 2 <= n)
        a[tr[x]].l = tr[x * 2];
        else
        a[tr[x]].l = -1;
        self(self, x * 2);
        if(x * 2 + 1 <= n)
        a[tr[x]].r = tr[x * 2 + 1];
        else
        a[tr[x]].r = -1;
        self(self, x * 2 + 1);
    };
    dfs(dfs, 1);
    for(int i = 1; i <= cnt; i ++ )
    {
        cout << "The father of node " << i << " is " << a[i].fa << ", ";
        cout << "the left child is " << a[i].l << ", ";
        cout << "and the right child is " << a[i].r << endl;
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
}