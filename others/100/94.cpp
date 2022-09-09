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
const ll mod = 1000000007;

template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

vector<LP> pieces;

void cut(ll id, ll pos) {
  vector<LP>::iterator itr = pieces.begin() + id;

  ll w = itr->first, d = itr->second;
  pieces.erase(itr);
  pos %= (w + d);

  if (pos < w) {
    LP p1 = make_pair(pos, d);
    LP p2 = make_pair(w - pos, d);
    if (pos > w - pos) swap(p1, p2);
    pieces.pb(p1); pieces.pb(p2);
  } else {
    pos = pos - w;
    LP p1 = make_pair(w, pos);
    LP p2 = make_pair(w, d - pos);
    if (pos > d - pos) swap(p1, p2);
    pieces.pb(p1); pieces.pb(p2);
  }
}

int main()
{
  ios::sync_with_stdio(false);

  while(true) {
    ll N, W, D;
    cin >> N >> W >> D;
    if (N == 0 && W == 0 && D == 0) break;

    pieces.clear();
    pieces.pb(make_pair(W, D));
    rep(i, N) {
      ll p, s;
      cin >> p >> s;
      cut(--p, s);
    }

    vl areas;
    rep(i, pieces.size()) {
      areas.pb(pieces[i].first * pieces[i].second);
    }
    sort(all(areas));
    rep(i, areas.size()) {
      cout << areas[i] << (i == areas.size() - 1 ? "\n" : " ");
    }
  }
}


