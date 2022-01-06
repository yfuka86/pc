#pragma GCC optimize("Ofast")
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <bitset>
#include <numeric>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();

template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

ll X, Y, E;
vector<vl> G;
vl match;
vector<bool> searched;

int dfs(int v){
	searched[v] = true;

	rep(i, G[v].size()) {
		int adj_node_id = G[v][i], pair_id = match[adj_node_id];
    //隣接するノードに、まだペアが存在しない
    //または、再帰的に繋ぎ直す
		if ((pair_id < 0) || (!searched[pair_id] && dfs(pair_id))){
			match[v] = adj_node_id;
			match[adj_node_id] = v;
			return true;
		}
	}
	return false;
}

int bipartite_matching(){
	int ret = 0;
  rep(v, X + Y) {
		if(match[v] < 0){
			rep(i, X + Y) searched[i] = false;
			if (dfs(v)){ ret++; }
		}
	}
	return ret;
}
int main()
{
  ios::sync_with_stdio(false);

  cin >> X >> Y >> E;
  G.resize(X + Y);
  match.resize(X + Y); match.assign(X + Y, -1);
  searched.resize(X + Y); searched.assign(X + Y, false);

  rep(i, E) {
    ll a, b; cin >> a >> b;
    G[a].pb(X + b);
    G[X + b].pb(a);
  }

  cout << bipartite_matching() << "\n";
}


