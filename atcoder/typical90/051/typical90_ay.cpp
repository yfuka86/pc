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

  ll N, K, P; cin >> N >> K >> P;
  vl a(N); rep(i, N) cin >> a[i];

  ll fN = (N + 1) / 2, lN = N - fN;


  vector<vl> fchoices(K + 1);
  vector<vl> lchoices(K + 1);
  fchoices[0].pb(0);
  lchoices[0].pb(0);

  rep(i, fN) {
    rep_r(j, K) {
      for (ll p: fchoices[j]) {
        if (p + a[i] <= P) fchoices[j + 1].pb(p + a[i]);
      }
    }
  }
  rep2(i, fN, N) {
    rep_r(j, K) {
      for (ll p: lchoices[j]) {
        if (p + a[i] <= P) lchoices[j + 1].pb(p + a[i]);
      }
    }
  }
  // coutmatrix(fchoices);
  // coutmatrix(lchoices);

  ll ans = 0;
  rep(i, K + 1) {
    sort(all(fchoices[i]));
    sort(all(lchoices[K - i]));

    for (ll p: fchoices[i]) {
      ll over = lchoices[K - i].end() - upper_bound(all(lchoices[K - i]), P - p);
      ans += lchoices[K - i].size() - over;
    }
  }


  cout << ans << "\n";
}


