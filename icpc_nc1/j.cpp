#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    vector<char> val = {' ', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    vector<char> col = {' ', 'C', 'D', 'H', 'S'};
    vector<vector<int>> mar(14, vector<int> (5)), mar2(14, vector<int> (5));
    vector<pair<int, int>> me(5), oppo(5);
    for(int i = 1; i <= 4; i ++ )
    {
        string s;
        cin >> s;
        // cout << "size:" << s.size() << endl;
        for(int j = 1; j <= 13; j ++ )
        {
            if(s[0] == val[j])
            {
                me[i].first = j;
                break;
            }
        }
        for(int j = 1; j <= 4; j ++ )
        {
            if(s[1] == col[j])
            {
                me[i].second = j;
                break;
            }
        }
        auto [x, y] = me[i];
        mar[x][y] = -1;
        mar2[x][y] = -1;
    }
    for(int i = 1; i <= 4; i ++ )
    {
        string s;
        cin >> s;
        for(int j = 1; j <= 13; j ++ )
        {
            if(s[0] == val[j])
            {
                oppo[i].first = j;
                break;
            }
        }
        for(int j = 1; j <= 4; j ++ )
        {
            if(s[1] == col[j])
            {
                oppo[i].second = j;
                break;
            }
        }
        auto [x, y] = oppo[i];
        mar[x][y] = -1;
        mar2[x][y] = -1;
    }
    // cout << '\t';
    // for(int i = 1; i <= 13; i ++ ) cout << i << '\t';
    // cout << endl;
    // for(int i = 1; i <= 4; i ++ )
    // {
    //     cout << i << '\t';
    //     for(int j = 1; j <= 13; j ++ )
    //     {
    //         cout << mar[j][i] << '\t';
    //     }
    //     cout << endl;
    // }
    // for(int i = 1; i <= 4; i ++ )
    // {
    //     cout << me[i].first << ' ' << me[i].second << endl;
    // }
    // cout << endl;
    // for(int i = 1; i <= 4; i ++ )
    // {
    //     cout << oppo[i].first << ' ' << oppo[i].second << endl;
    // }
    int rank_oppo_max = 1;
    for(int i1 = 1; i1 <= 13; i1 ++ )
    {
        for(int j1 = 1; j1 <= 4; j1 ++ )
        {
            if(mar[i1][j1] == -1) continue;
            oppo.push_back({i1, j1});
            vector<pair<int, int>> tmp = oppo;
            sort(tmp.begin() + 1, tmp.end());
            // for(int i = 1; i <= 5; i ++ )
            // {
            //     cout << tmp[i].first << ' ' << tmp[i].second << endl;
            // }
            // cout << endl;
            int cnt = 0, cnt_mx = 1, cnt_pair = 0, same = 1, straight = 1, now = 0, rank_oppo = 1;
            for(int i = 1; i <= 5; i ++ )
            {
                if(i < 5)
                {
                    if(tmp[i].second != tmp[i + 1].second) same = 0;
                    if(tmp[i].first - tmp[i + 1].first != -1) straight = 0;
                }
                // cout << "now: " << i << ' ' << now << endl;
                if(cnt != tmp[i].first)
                {
                    cnt = tmp[i].first;
                    if(now == 2) cnt_pair ++;
                    now = 1;
                    continue;
                }
                now ++;
                cnt_mx = max(cnt_mx, now);
            }
            if(now == 2) cnt_pair ++;
            cnt_mx = max(cnt_mx, now);
            // cout << cnt_mx << ' ' << cnt_pair << " " << same << " " << straight << " " << now << ' ' << rank_oppo << endl;
            int flag = 1;
            if(tmp[5].first == 13 && tmp[1].first == 1)
            {
                for(int i = 1; i < 4; i ++ )
                {
                    if(tmp[i].first - tmp[i + 1].first != -1) flag = 0;
                }
                straight = flag;
            }
            if(cnt_mx == 4)
            {
                rank_oppo = max(rank_oppo, 8ll);
            }
            if(cnt_mx == 3)
            {
                if(cnt_pair)
                {
                    rank_oppo = max(rank_oppo, 7ll);
                }
                else rank_oppo = max(rank_oppo, 4ll);
            }
            if(cnt_pair)
            {
                if(cnt_pair == 2) rank_oppo = max(rank_oppo, 3ll);
                if(cnt_pair == 1) rank_oppo = max(rank_oppo, 2ll);
            }
            if(same || straight)
            {
                if(straight)
                {
                    if(same)
                    {
                        if(oppo[1].first == 10) rank_oppo = max(rank_oppo, 10ll);
                        else rank_oppo = max(rank_oppo, 9ll);
                    }
                    else rank_oppo = max(rank_oppo, 5ll);
                }
                if(same)
                {
                    rank_oppo = max(rank_oppo, 6ll);
                }
            }
            mar[i1][j1] = rank_oppo;
            oppo.pop_back();
            rank_oppo_max = max(rank_oppo_max, rank_oppo);
        }
        // cout << endl;
    }
    // cout << "oppo:" << endl;
    // cout << '\t';
    // for(int i = 1; i <= 13; i ++ ) cout << i << '\t';
    // cout << endl;
    // for(int i = 1; i <= 4; i ++ )
    // {
    //     cout << i << '\t';
    //     for(int j = 1; j <= 13; j ++ )
    //     {
    //         cout << mar[j][i] << '\t';
    //     }
    //     cout << endl;
    // }
    int rank_me_max = 1;
    for(int i1 = 1; i1 <= 13; i1 ++ )
    {
        for(int j1 = 1; j1 <= 4; j1 ++ )
        {
            if(mar2[i1][j1] == -1) continue;
            me.push_back({i1, j1});
            vector<pair<int, int>> tmp = me;
            sort(tmp.begin() + 1, tmp.end());
            int cnt = 0, cnt_mx = 1, cnt_pair = 0, same = 1, straight = 1, now = 1, rank_me = 1;
            for(int i = 1; i <= 5; i ++ )
            {
                if(i < 5)
                {
                    if(tmp[i].second != tmp[i + 1].second) same = 0;
                    if(tmp[i].first - tmp[i + 1].first != -1) straight = 0;
                }
                // cout << "now: " << i << ' ' << now << endl;
                if(cnt != tmp[i].first)
                {
                    cnt = tmp[i].first;
                    if(now == 2) cnt_pair ++;
                    now = 1;
                    // cout << "cnt: " << i << ' ' << cnt << endl;
                    continue;
                }
                // cout << "cnt: " << i << ' ' << cnt << endl;
                now ++;
                cnt_mx = max(cnt_mx, now);
            }
            cnt_mx = max(cnt_mx, now);
            // cout << cnt_mx << ' ' << cnt_pair << " " << same << " " << straight << " " << now << ' ' << rank_me << endl;
            if(now == 2) cnt_pair ++;
            int flag = 1;
            if(tmp[5].first == 13 && tmp[1].first == 1)
            {
                for(int i = 1; i < 4; i ++ )
                {
                    if(tmp[i].first - tmp[i + 1].first != -1) flag = 0;
                }
                straight = flag;
            }
            if(cnt_mx == 4)
            {
                rank_me = max(rank_me, 8ll);
            }
            if(cnt_mx == 3)
            {
                if(cnt_pair)
                {
                    rank_me = max(rank_me, 7ll);
                }
                else rank_me = max(rank_me, 4ll);
            }
            if(cnt_pair)
            {
                if(cnt_pair == 2) rank_me = max(rank_me, 3ll);
                if(cnt_pair == 1) rank_me = max(rank_me, 2ll);
            }
            if(same || straight)
            {
                if(straight)
                {
                    if(same)
                    {
                        if(me[1].first == 10) rank_me = max(rank_me, 10ll);
                        else rank_me = max(rank_me, 9ll);
                    }
                    else rank_me = max(rank_me, 5ll);
                }
                if(same)
                {
                    rank_me = max(rank_me, 6ll);
                }
            }
            mar2[i1][j1] = rank_me;
            me.pop_back();
            rank_me_max = max(rank_me, rank_me_max);
        }
        // cout << endl;
    }
    // cout << "me:" << endl;
    // cout << '\t';
    // for(int i = 1; i <= 13; i ++ ) cout << i << '\t';
    // cout << endl;
    // for(int i = 1; i <= 4; i ++ )
    // {
    //     cout << i << '\t';
    //     for(int j = 1; j <= 13; j ++ )
    //     {
    //         cout << mar2[j][i] << '\t';
    //     }
    //     cout << endl;
    // }
    int i_win = 1, oppo_win = 1;
    for(int i = 1; i <= 13; i ++ )
    {
        for(int j = 1; j <= 4; j ++ )
        {
            if(mar[i][j] == -1) continue;
            int rank_c = mar[i][j];
            int flag_i = 0, flag_oppo = 0;
            for(int x = 1; x <= 13; x ++ )
            {
                for(int y = 1; y <= 4; y ++ )
                {
                    if((x == i && y == j) || mar[x][y] == -1) continue;
                    int rank_p = mar2[x][y];
                    flag_i |= (rank_c < rank_p);
                    flag_oppo |= (rank_c > rank_p);
                    if(rank_c == rank_p)
                    {
                        cout << "PaiMeiYouWenTi" << endl;
                        return;
                    }
                }
            }
            i_win &= flag_i;
            oppo_win &= flag_oppo;
        }
    }
    if(i_win && !oppo_win)
    {
        cout << "WoYaoYanPai" << endl;
        return;
    }
    if(!i_win && oppo_win)
    {
        cout << "GeiWoCaPiXie" << endl;
        return;
    }
    cout << "PaiMeiYouWenTi" << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    // cout << (char)49 << endl;
    while(t -- )
    {
        solve();
    }
    return 0;
}