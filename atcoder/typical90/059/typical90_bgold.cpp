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
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();

int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = 0; i < d; i++) cout << (a >> d) & 1; cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, M, Q; cin >> N >> M >> Q;

  vector<vl> G(N);
  // x < y の性質ゆえトポロジカルソート不必要
  rep(i, M) {
    ll x, y; cin >> x >> y; x--; y--;
    G[y].pb(x);
  }

  vector<LP> q(Q);
  rep(i, Q) {
    ll a, b; cin >> a >> b; a--; b--;
    q[i] = mp(a, b);
  }

  auto calc = [&](vector<ull>& dp) -> void{
    rep(i, N) {
      for (ll from: G[i]) {
        dp[i] |= dp[from];
      }
    }
  };

  // rep(i, Q) {
  //   vl dp(N, 0);
  //   dp[q[i].first] = 1;
  //   calc(dp);
  //   if (dp[q[i].second] == 1) cout << "Yes" << "\n"; else cout << "No" << "\n";
  // }

  ll cur = 0;
  while(cur * 64 < Q) {
    vector<ull> dp(N, 0);
    rep(i, 64) {
      if (cur * 64 + i >= Q) break;
      LP p = q[cur * 64 + i];
      dp[p.first] |= (1ULL << i);
    }
    calc(dp);
    rep(i, 64) {
      if (cur * 64 + i >= Q) break;
      LP p = q[cur * 64 + i];
      if ((dp[p.second] >> i) & 1) cout << "Yes" << "\n"; else cout << "No" << "\n";
    }
    cur++;
  }
}


