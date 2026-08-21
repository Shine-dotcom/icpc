#include<bits/stdc++.h>
#include<random>
using namespace std;
#define int long long
// #define endl '\n'
void solve()
{
    int n;
    cin >> n;
    mt19937 rng(random_device{}());
    uniform_int_distribution uni(1, 3);
    if(n == 3)
    {
        cout << "! 1 2 3" << endl;
        return;
    }
    int t = -1;
    int i = 1, j = 2, k = 3;
    while(1)
    {
        cout << "? " << i << ' ' << j << ' ' << k << endl;
        cin >> t;
        if(t)
        {
            int choice = uni(rng);
            if(choice == 1)
            {
                i = t;
            }
            if(choice == 2)
            {
                j = t;
            }
            if(choice == 3)
            {
                k = t;
            }
        }
        else
        {
            break;
        }
    }
    cout << "! " << i << ' ' << j << ' ' << k << endl;
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
    return 0;
}