#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define x first
#define y second
const int N = 25;
int w, h;
char c[N][N];
pair<int, int> st = {0, 0};
int bfs()
{
    int ans = 1;
    queue<pair<int, int>> q;
    q.push(st);
    while(q.size())
    {
        pair<int, int> t = q.front();
        q.pop();
        if(t.x > h || t.y > w || t.x <= 0 || t.y <= 0) continue;
        // cout << t.x << ' ' << t.y << ' ' << ans << endl;
        if(c[t.x][t.y] == '.')
        {
            ans ++;
            c[t.x][t.y] = '@';
        }
        if(c[t.x - 1][t.y] == '.') q.push({t.x - 1, t.y});
        if(c[t.x + 1][t.y] == '.') q.push({t.x + 1, t.y});
        if(c[t.x][t.y + 1] == '.') q.push({t.x, t.y + 1});
        if(c[t.x][t.y - 1] == '.') q.push({t.x, t.y - 1});
    }
    return ans;
}
void solve()
{
    while(1)
    {
        cin >> w >> h;
        if(!w || !h) break;
        for(int i = 1; i <= h; i ++ )
        {
            for(int j = 1; j <= w; j ++ )
            {
                cin >> c[i][j];
                if(c[i][j] == '@') st = {i, j};
            }
        }
        cout << bfs() << endl;
        // for(int i = 1; i <= h; i ++ )
        // {
        //     for(int j = 1; j <= w; j ++ )
        //     {
        //         cout << c[i][j];
        //     }
        //     cout << endl;
        // }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t -- ) solve();
    return 0;
}