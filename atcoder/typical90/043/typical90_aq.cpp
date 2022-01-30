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
template<typename T> void coutbin(T &a, int d) { for (int i = 0; i < d; i++) cout << (a >> d) & 1; cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll H, W; cin >> H >> W;
  LP S, T; cin >> S.first >> S.second >> T.first >> T.second;
  S.first--; S.second--; T.first--; T.second--;
  vector<vb> maze(H, vb(W, false));
  rep(i, H) {
    string s; cin >> s;
    rep(j, W) if (s[j] == '.') maze[i][j] = true;
  }

  // (costsofar, direction) (x, y)
  priority_queue<pair<LP, LP>, vector<pair<LP, LP>>, greater<pair<LP, LP>>> que;
  vector<vl> cost(H, vl(W, LINF));

  que.push(mp(mp(0, -1), S));

  vector<vl> dxdy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  while(!que.empty()) {
    auto data = que.top(); que.pop();
    auto [c, dir] = data.first;
    auto [x, y] = data.second;
    // cout << c << " " << dir << " " << x << ":" << y << endl;
    if (x < 0 || x >= H || y < 0 || y >= W || !maze[x][y] || cost[x][y] < c) continue;

    cost[x][y] = c;
    // cout << c << endl;
    rep(i, 4) {
      if (i == 0 && dir == 1) continue;
      if (i == 1 && dir == 0) continue;
      if (i == 2 && dir == 3) continue;
      if (i == 3 && dir == 2) continue;

      LP next = mp(x + dxdy[i][0], y + dxdy[i][1]);
      if (i == dir) {
        que.push(mp(mp(c, i), next));
      } else {
        que.push(mp(mp(c + 1, i), next));
      }
    }
  }

  cout << cost[T.first][T.second] - 1 << "\n";
}


