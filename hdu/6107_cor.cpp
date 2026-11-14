#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100005;
const int LOG = 20;   // 2^20 > 1e5，足够把行数压到 n 以内

int n, W, pw, dw;
ll a[MAXN], pre[MAXN];
int fullRow[MAXN][LOG];  // 无图整行：从 i 开始，2^j 行能放的词数
int picRow[MAXN][LOG];   // 图片行：从 i 开始，2^j 个图片行能放的词数

// 一行宽 width，从第 i 个词开始最多能放几个词（词间空一格）
int fitCount(int i, ll width) {
    if (i > n) return 0;
    if (a[i] > width) return 0;               // 单个词都放不下
    int lo = i, hi = n, ans = i;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        ll cost = (pre[mid] - pre[i - 1]) + (mid - i); // 字符数 + 空格数
        if (cost <= width) ans = mid, lo = mid + 1;
        else hi = mid - 1;
    }
    return ans - i + 1;
}

void build() {
    int rw = W - pw - dw;                      // 右留白
    for (int i = 1; i <= n; i++) {
        fullRow[i][0] = fitCount(i, W);        // 普通整行
        int lc = fitCount(i, dw);              // 图片行左留白
        int nxt = i + lc;                      // 右留白从 nxt 开始
        picRow[i][0] = lc + fitCount(nxt, rw); // 图片行 = 左 + 右
    }
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            int m = i + fullRow[i][j - 1];
            fullRow[i][j] = fullRow[i][j - 1] + (m <= n ? fullRow[m][j - 1] : 0);
            m = i + picRow[i][j - 1];
            picRow[i][j] = picRow[i][j - 1] + (m <= n ? picRow[m][j - 1] : 0);
        }
    }
}

int goFull(int i, int rows) {                  // 走 rows 个整行
    for (int j = 0; j < LOG; j++)
        if (rows >> j & 1) i += fullRow[i][j];
    return i;
}
int goPic(int i, int rows) {                   // 走 rows 个图片行
    for (int j = 0; j < LOG; j++)
        if (rows >> j & 1) i += picRow[i][j];
    return i;
}

int needFull(int i) {                          // 无图放完 i..n 需要几行
    if (i > n) return 0;
    int rows = 0;
    for (int j = LOG - 1; j >= 0; j--) {
        if (i + fullRow[i][j] <= n) {          // 2^j 行还没放完
            rows += (1 << j);
            i += fullRow[i][j];
        }
    }
    return rows + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        cin >> n >> W >> pw >> dw;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
        build();
        int Q; cin >> Q;
        while (Q--) {
            ll x, h; cin >> x >> h;
            ll need = needFull(1);             // 无图时全部词需要几行
            ll ans;
            if (need < x) {                    // 词在图之前就放完了
                ans = need + h;                // 图紧跟在词后面
            } else {
                int p = goFull(1, (int)min(x - 1, (ll)n)); // 图上方的 x-1 行
                p = goPic(p, (int)min(h, (ll)n));          // 图占的 h 行
                ans = (x - 1) + h + needFull(p);           // 图下方的剩余词
            }
            cout << ans << '\n';
        }
    }
    return 0;
}