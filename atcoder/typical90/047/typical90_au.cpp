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

// Rolling hash
const ll P_B = 17, P_M = 1e9 + 7;
vl bf(1e6 + 10, -1);
ll b_fact(ll p) {
  if (bf[p] == -1) { bf[0] = 1; rep(i, 1e6 + 9) bf[i + 1] = bf[i] * P_B % P_M; }
  return bf[p];
}

vl s_hash(vl& s) {
  vl h(s.size() + 1, 0);
  rep(i, s.size()) { h[i + 1] = (P_B * h[i] + s[i]) % P_M; }
  return h;
}

ll substr_hash(vl& h, ll l, ll r) {
  assert(0 <= l && l < r && r <= h.size());
  ll ret = h[r] - (b_fact(r - l) * h[l] % P_M); if (ret < 0) ret += P_M;
  return ret;
}
//


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N; cin >> N;
  string s, t; cin >> s >> t;
  string color = "RGB";
  vl S(N), T(N);

  rep(i, N) {
    rep(j, 3) {
      if (s[i] == color[j]) S[i] = j;
      if (t[i] == color[j]) T[i] = j;
    }
  }
  vl rst(N), gst(N), bst(N);
  rep(i, N) {
    if (T[i] == 0) {
      rst[i] = 0; gst[i] = 2; bst[i] = 1;
    } else if (T[i] == 1) {
      rst[i] = 2; gst[i] = 1; bst[i] = 0;
    } else {
      rst[i] = 1; gst[i] = 0; bst[i] = 2;
    }
  }

  vl sh = s_hash(S);
  vector<vl> th(3);
  th[0] = s_hash(rst);
  th[1] = s_hash(gst);
  th[2] = s_hash(bst);

  ll ans = 0;
  rep(i, N - 1) {
    rep(j, 3) {
      if (substr_hash(sh, N - i - 1, N) == substr_hash(th[j], 0, i + 1)) { ans++; break; }
    }
    rep(j, 3) {
      if (substr_hash(sh, 0, i + 1) == substr_hash(th[j], N - i - 1, N)) { ans++; break; }
    }
  }
  rep(j, 3) {
    if (substr_hash(sh, 0, N) == substr_hash(th[j], 0, N)) { ans++; break; }
  }

  cout << ans << "\n";
}


