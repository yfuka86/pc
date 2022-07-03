#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
#ifdef DEBUG
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    os << '{';
    for(int i = 0; i < (int)v.size(); i++) {
        if(i) { os << ','; }
        os << v[i];
    }
    os << '}';
    return os;
}
void debugg() { cerr << endl; }
template <class T, class... Args>
void debugg(const T &x, const Args &... args) {
    cerr << " " << x;
    debugg(args...);
}
#define debug(...)                                                             \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]: ", debugg(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

struct Setup {
    Setup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(15);
    }
} __Setup;

using ll = long long;
#define OVERLOAD3(_1, _2, _3, name, ...) name
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define REP1(i, n) for(int i = 0; i < int(n); i++)
#define REP2(i, a, b) for(int i = (a); i < int(b); i++)
#define REP(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())
#define SZ(v) ((int)(v).size())
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
constexpr int MOD = 1000000007;
constexpr int MOD2 = 998244353;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void Case(int i) { cout << "Case #" << i << ": "; }
int popcount(int x) { return __builtin_popcount(x); }
ll popcount(ll x) { return __builtin_popcountll(x); }
#pragma endregion Macros

int main() {
    int N, Q;
    ll X;
    cin >> N >> Q >> X;
    vector<ll> w(N), sum(2*N + 1, 0);
    REP(i, N) cin >> w[i];
    REP(i, 2*N) sum[i+1] = sum[i] + w[i%N];

    vector<int> to(N, -1);
    REP(i, N) {
        ll rest = X - (X / sum[N]) * sum[N];
        int r = lower_bound(sum.begin() + i, sum.begin() + (i + N), sum[i] + rest) - sum.begin();
        to[i] = r % N;
    }
    debug(to);

    vector db(61, vector<int>(N, -1));
    REP(i, N) db[0][i] = to[i];
    REP(k, 60) {
        REP(i, N) {
            db[k+1][i] = db[k][db[k][i]];
        }
    }

    REP(_, Q) {
        ll K;
        cin >> K;
        K--;
        int now = 0;
        REP(i, 61) if(K >> i & 1) {
            now = db[i][now];
        }
        int r = to[now];
        debug(now, r);
        ll rest = X - (X / sum[N]) * sum[N];
        if(rest > 0 and r <= now) r += N;
        ll ans = (X / sum[N]) * N + ll(r - now);
        cout << ans << '\n';
    }
}
