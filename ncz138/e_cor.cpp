#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;
    cin>>n;
    vector<ll>a(n+1);
    vector<ll>dp(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    ll max1=-1e18,max0=-1e18;
    for(int i=1;i<=n;i++) {
        dp[i]=dp[i-1];
        if(a[i]%2==0) {
            dp[i]=max(dp[i],max0+a[i]);
            for(int i = 1; i <= n; i ++ )
            {
                cout << dp[i] << ' ';
            }
            cout << endl;
            max0=max(dp[i-1]+a[i],max0);
            cout << "max0: " << max0 << endl;
        }
        else {
            dp[i]=max(dp[i],max1+a[i]);
            for(int i = 1; i <= n; i ++ )
            {
                cout << dp[i] << ' ';
            }
            cout << endl;
            max1=max(dp[i-1]+a[i],max1);
            cout << "max1: " << max1 << endl;
        }
    }
    cout<<dp[n]<<endl; 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    solve();
    return 0;
}