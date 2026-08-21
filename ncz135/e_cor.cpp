#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int t;
	cin>>t;
	while(t>0){
		t--;
		int n;
		cin>>n;
		vector<int>a(n);
		vector<int>b(n);
		vector<int>c(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		for(int i=0;i<n;i++){
			cin>>c[i];
		}
		vector<vector<int>>dp(n+1,vector<int>(5,1e18));
		if(a[0]>2){
			dp[0][0]=2*c[0];
		}
	    if(a[0]>1){
			dp[0][1]=c[0];
		}
	    dp[0][2]=0;
	    dp[0][3]=b[0];
	    dp[0][4]=2*b[0];
	    for(int i=1;i<n;i++){
			for(int j=-2;j<=2;j++){
				for(int k=-2;k<=2;k++){
					if(a[i]+j==a[i-1]+k){
						continue;
					}
					if(a[i]+j<=0){
						continue;
					}
					if(j+2>=2){
					dp[i][j+2]=min(dp[i][j+2],dp[i-1][k+2]+abs(j)*b[i]);
					}
					else if(j+2<2){
						dp[i][j+2]=min(dp[i][j+2],dp[i-1][k+2]+abs(j)*c[i]);
					}
				}
			}
		}
		int ans=1e18;
        for(int j = 0; j <= 4; j ++ )
        {
            for(int i = 0; i < n; i ++ )
            {
                cout << (dp[i][j] == 1e18 ? -1 : dp[i][j]) << '\t';
            }
            cout << endl;
        }
		for(int i=0;i<5;i++){
			ans=min(ans,dp[n-1][i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}

/*
为什么变化量的绝对值不超过2？ -> 经验性问题
*/