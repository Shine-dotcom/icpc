#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    bool is_pos = 0;
    int fac = 0;
    int sum = 0;
    int fac_t = 0;
    int sum_t = 0;
    bool is_var = 0;
    bool has_been_var = 0;
    string s;
    cin >> s;
    char v = 0;
    for(int i = s.length() - 1; i >= 0; i -- )
    {
        int base = 1;
        if(s[i] == '=')
        {
            if(is_var) fac_t = 1, is_var = 0;
            fac -= fac_t;
            sum -= sum_t;
            sum_t = 0;
            fac_t = 0;
            is_pos = 1;
        }
        while(i >= 0 && s[i] >= '0' && s[i] <= '9')
        {
            int val = s[i] - '0';
            if(is_var)
            {
                has_been_var = 1;
                fac_t += val * base;
            }
            else
            {
                sum_t += val * base;
            }
            base *= 10;
            if(s[i - 1] < '0' || s[i - 1] > '9')
            {
                is_var = 0;
                break;
            }
            i --;
        }
        base = 1;
        if(s[i] == '-')
        {
            if(is_var == 1) fac_t = 1;
            if(is_pos)
            {
                // cout << 222 << endl;
                fac -= fac_t;
                sum -= sum_t;
                fac_t = 0;
                sum_t = 0;
            }
            else
            {
                fac += fac_t;
                sum += sum_t;
                fac_t = 0;
                sum_t = 0;
            }
            is_var = 0;
        }
        if(s[i] == '+')
        {
            if(is_var == 1) fac_t = 1;
            if(is_pos)
            {
                fac += fac_t;
                sum += sum_t;
                fac_t = 0;
                sum_t = 0;
            }
            else
            {
                fac -= fac_t;
                sum -= sum_t;
                fac_t = 0;
                sum_t = 0;
            }
            is_var = 0;
        }
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            is_var = 1;
            if(has_been_var == 0)
            {
                v = s[i];
            }
        }
        // cout << sum << ' ' << fac << endl;
    }
    if(is_var == 1) fac_t = 1;
    fac += fac_t;
    sum += sum_t;
    // cout << endl;
    // cout << sum << ' ' << fac << endl;
    double ans = (-1.0 * sum) / (1.0 * fac);
    if(ans == 0)
    {
        ans = 0.000;
    }
    cout << v << '=';
    cout << fixed << setprecision(3) << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t -- )  solve();
    return 0;
}