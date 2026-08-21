#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
ll n;
ll a[N];


void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    sort(a+1,a+1+n);
    if(n==1||a[1]==a[n])
    {
        cout<<-1<<'\n';
        return ;
    }
    int x = (n+1)/2;

    int cnt1 = 0,cnt2=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<a[x])cnt1++;
        else if(a[i]>a[x])cnt2++;
    }

    ll ans =  n-1;
    ans = min(ans,n-2*cnt1);
    ans = min(ans,n-2*cnt2+1);
    cout<<ans<<'\n';
    




    


    



}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();

    }


    return 0;
}