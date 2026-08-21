// 绝对值不等式（自己百度）
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	for(int i = 1; i <= n; i ++ )
	{
		int l = 0, r = 0;
		for(int j = i + 1; j <= n; j ++ )
		{
			if(a[i] > a[j]) l ++;
			if(a[j] > a[i]) r ++;
		}
		cout << max(l, r) << ' ';
	}
	cout << endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while(t -- )
	{
		solve();
	}
}
