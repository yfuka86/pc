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
template<typename T> void coutarray(vector<T>& v, ll offset = 0) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i] + offset;} cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = 0; i < d; i++) cout << (a >> d) & 1; cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, M, K; cin >> N >> M >> K;
  vector<vl> G(N);
  vl deg(N, 0);
  rep(i, M) {
    ll a, b; cin >> a >> b; a--; b--;
    G[a].pb(b);
    deg[b]++;
  }

  vl st;
  rep(i, N) if (deg[i] == 0) st.pb(i);
	vl perm(N, -1);
	vector<vl> answer_list;

	function<bool(int)> dfs = [&](int depth) {
		if (depth == N) { answer_list.push_back(perm); return true; }
		if (st.empty()) return false;

    rep_r(i, st.size()) {
			if (answer_list.size() == K) break;

			int x = st[i];
			st.erase(st.begin() + i);

			for (int j : G[x]) {
				deg[j]--;
				if (deg[j] == 0) st.push_back(j);
			}

			perm[depth] = x;
			if (!dfs(depth + 1)) return false;

			for (int j : G[x]) {
				if (deg[j] == 0) st.pop_back();
				deg[j]++;
			}

			st.insert(st.begin() + i, x);
		}
    // coutarray(perm, 1);
		return true;
	};

	dfs(0);

	if (answer_list.size() != K) { cout << -1 << "\n"; return 0; }
	for (vl v : answer_list) rep(i, N) cout << v[i] + 1 << (i == N - 1 ? "\n" : " ");
}
