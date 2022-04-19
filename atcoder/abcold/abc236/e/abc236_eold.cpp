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

  ll n; cin >> n;
  vl a(n); rep(i, n) cin >> a[i];

  ll ok = 0;
  ll ng = LINF;

  ll scale = 1e3;
  while (ng - ok > 1) {
    ll mid = (ok + ng) / 2;
    vector<ll> sum(n + 1, -INF);
    sum[0] = 0;
    rep(i, n) {
      if (i < n - 1) chmax(sum[i + 2], sum[i] + a[i + 1] * scale - mid);
      chmax(sum[i + 1], sum[i] + a[i] * scale - mid);
    }
    // coutarray(sum);
    if (sum[n] >= 0 || sum[n - 1] >= 0) {
      ok = mid;
    } else {
      ng = mid;
    }
    // cout << mid << ":" << ok << endl;
  }
  cout << fixed << setprecision(10) << (ok / (ld)scale) << "\n";

  ll mok = 0;
  ll mng = INF;

  while (mng - mok > 1) {
    ll mid = (mok + mng) / 2;
    ll count = 0;
    ll last = -1;
    rep(i, n) {
      if (a[i] >= mid) {
        count++;
        last = i;
      } else if (i - last > 1) {
        count--;
        last = i;
      }
    }
    if (count > 0) {
      mok = mid;
    } else {
      mng = mid;
    }
  }
  cout << mok << "\n";
}


