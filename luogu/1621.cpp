#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
	int a, b, p;
	cin >> a >> b >> p;
	vector<int> f(b - a + 2);
	for(int i = 1; i <= b - a + 1; i ++ )
	{
		f[i] = i;
	}
	// for(int i = 1; i <= b - a + 1; i ++ )
	// {
		// cout << f[i] << " \n" [i == b];
	// }
	auto find = [&](auto self, int x) -> int
	{
		return f[x] = (f[x] == x ? x : self(self, f[x]));
	};
	auto merge = [&](int x, int y) -> void
	{
		int fx = find(find, x), fy = find(find, y);
		f[fx] = fy;
	};
	vector<int> prime(b + 1);
	vector<int> st(b + 1);
	int cnt = 0;
	for(int i = 2; i <= b; i ++ )
	{
		if(st[i] == 0)
		prime[cnt ++ ] = i;
		for(int j = 0; prime[j] <= b / i; j ++ )
		{
			st[prime[j] * i] = 1;
			if(i % prime[j] == 0) break;
		}
	}
	for(int i = 1; i <= b; i ++ ) st[i] = 0;
	vector<vector<int>> primes(b + 1);
// 	
	for(int i = a; i <= b; i ++ )
	{
		for(int j = 0 ;j < cnt; j ++ )
		{
			if(st[prime[j]] == 0 && i % prime[j] == 0)
			{
				st[prime[j]] = 1;
				if(prime[j] >= p)
				for(int k = i; k <= b; k += prime[j])
				{
					merge(k - a + 1, i - a + 1);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= b - a + 1; i ++ )
	{
		if(f[i] == i) ans ++;
		// cout << f[i] << ' ';
	}
	cout << ans << endl;
	// for(auto pr : prime)
	// cout << pr << ' ';
	// cout << endl;
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



// 未解决 https://www.luogu.com.cn/problem/P1621