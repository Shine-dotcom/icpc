#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
	int r, g, b;
	cin >> r >> g >> b;
	int rg = 0, rb = 0, gb = 0;
	string s = "";
	while((r > 0) + (g > 0) + (b > 0) >> 1)
	{
		if(r >= b && g >= b)
		{
			if(r && g) rg ++, r --, g --;
	//		cout << "111" << endl;
		}
		else if(r >= g && b >= g)
		{
			if(r && b) rb ++, r --, b --;
	//		cout << "222" << endl;
		}
		else if(g >= r && b >= r)
		{
			if(g && b) gb ++, g --, b --;
	//		cout << "333" << endl;
		}
	}
	cout << rg << ' ' << rb << ' ' << gb << ' ' << endl;
	cout << r << ' ' << g << ' ' << b << endl;
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
	return 0;
}
