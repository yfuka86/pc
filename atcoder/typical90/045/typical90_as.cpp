#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=sta;i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max() / 3;
const ll LINF = LLONG_MAX / 3;
const double DINF = numeric_limits<double>::infinity();

int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a) { cout << bitset<16>(a) << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, K; cin >> N >> K;
  vector<LP> v(N);
  rep(i, N) {
    ll x, y; cin >> x >> y;
    v[i] = mp(x, y);
  }

  vector<vl> dist(N, vl(N, 0));
  rep(i, N) {
    rep(j, N) {
      if (i == j) continue;
      ll xd = (v[i].first - v[j].first);
      ll yd = (v[i].second - v[j].second);
      dist[i][j] = xd * xd + yd * yd;
    }
  }
  // coutmatrix(dist);

  vl sdist(1 << N, 0);
  vector<vl> dp(1 << N, vl(K + 1, LINF));
  dp[0][0] = 0;

  rep(S, 1 << N) {
    rep(i, N) {
      rep2(j, i + 1, N) {
        if ((S >> i & 1) && (S >> j & 1)) chmax(sdist[S], dist[i][j]);
      }
    }
    for (ll s = S; s != 0; s = (s - 1) & S) {
      rep(i, K) {
        if (dp[S - s][i] == LINF) continue;
        chmin(dp[S][i + 1], max(dp[S - s][i], sdist[s]));
      }
    }
  }
  // coutmatrix(dp);

  cout << dp[(1 << N) - 1][K] << "\n";
}


