#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int MAXN = 1e6 + 10;
int phi[MAXN], st[MAXN], prime[MAXN], cnt;
bool has_root[MAXN];
vector<int> factors[MAXN];

// 线性筛求欧拉函数和质数
void euler() {
    phi[1] = 1;
    cnt = 0;
    for(int i = 2; i < MAXN; i++) {
        if(!st[i]) {
            prime[cnt++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; j < cnt && prime[j] * i < MAXN; j++) {
            st[prime[j] * i] = 1;
            if(i % prime[j] == 0) {
                phi[i * prime[j]] = prime[j] * phi[i];
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}

// 预处理每个数的质因子
void init_factors() {
    for(int i = 2; i < MAXN; i++) {
        if(factors[i].empty()) {
            for(int j = i; j < MAXN; j += i) {
                factors[j].push_back(i);
            }
        }
    }
}

// 标记有原根的数
void mark_roots() {
    // 根据原根存在定理：
    // n有原根当且仅当 n = 2, 4, p^k, 2p^k (p为奇素数)
    has_root[2] = has_root[4] = true;
    
    for(int i = 1; i < cnt; i++) { // 从1开始跳过2
        int p = prime[i]; // 奇素数
        int power = p;
        
        while(power < MAXN) {
            has_root[power] = true;
            if(2 * power < MAXN) {
                has_root[2 * power] = true;
            }
            if(power > MAXN / p) break;
            power *= p;
        }
    }
}

// 快速幂
int ksm(int a, int b, int mod) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

// 检查g是否是n的原根
bool is_primitive_root(int g, int n) {
    if(__gcd(g, n) != 1) return false;
    
    int t = phi[n];
    for(int p : factors[t]) {
        if(ksm(g, t / p, n) == 1) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, d;
    cin >> n >> d;
    
    if(!has_root[n]) {
        cout << 0 << endl << endl;
        return;
    }
    
    vector<int> roots;
    
    // 找最小原根
    int min_root = -1;
    for(int i = 1; i < n; i++) {
        if(__gcd(i, n) == 1 && is_primitive_root(i, n)) {
            min_root = i;
            break;
        }
    }
    
    if(min_root == -1) {
        cout << 0 << endl << endl;
        return;
    }
    
    // 通过最小原根生成所有原根
    int phi_n = phi[n];
    for(int i = 1; i <= phi_n; i++) {
        if(__gcd(i, phi_n) == 1) {
            roots.push_back(ksm(min_root, i, n));
        }
    }
    
    sort(roots.begin(), roots.end());
    
    cout << roots.size() << endl;
    int output_count = roots.size() / d;
    for(int i = 0; i <= output_count; i++) {
        if(i * d - 1 < roots.size())
        cout << roots[i * d - 1] << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    euler();
    init_factors();
    mark_roots();
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}