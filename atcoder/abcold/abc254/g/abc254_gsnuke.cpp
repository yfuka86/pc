#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using P = pair<int,int>;

void chmax(int& x, int y) { x = max(x,y);}

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<P>> es(n); // elevator
  rep(i,m) {
    int a, b, c;
    cin >> a >> b >> c;
    --a;
    es[a].emplace_back(b,c);
  }
  rep(i,n) {
    vector<P> pe; // prev
    swap(es[i],pe);
    vector<P>& ne = es[i]; // new
    sort(pe.begin(), pe.end());
    for (auto [l,r] : pe) {
      if (ne.size() && ne.back().second >= l) {
        chmax(ne.back().second, r);
      } else {
        ne.emplace_back(l,r);
      }
    }
  }

  vector<P> ce; // combined elevator
  rep(i,n) ce.insert(ce.end(), es[i].begin(), es[i].end());
  {
    vector<P> pe; // prev
    swap(ce,pe);
    sort(pe.begin(),pe.end());
    for (auto [l,r] : pe) {
      if (ce.size() && ce.back().second >= r) continue;
      ce.emplace_back(l,r);
    }
  }

  const int INF = 1001001001;
  auto get = [&](int x) {
    int i = upper_bound(ce.begin(), ce.end(), P(x,INF))-ce.begin()-1;
    if (i == -1) return -1;
    if (x <= ce[i].second) return i;
    return -1;
  };

  m = ce.size();
  const int D = 19;
  vector d(D, vector<int>(m));
  rep(i,m) d[0][i] = get(ce[i].second);
  rep(i,D-1) {
    rep(j,m) d[i+1][j] = d[i][d[i][j]];
  }

  auto goUp = [&](int i, int x) {
    int j = upper_bound(es[i].begin(), es[i].end(), P(x,INF))-es[i].begin()-1;
    if (j == -1) return x;
    if (x <= es[i][j].second) return es[i][j].second;
    return x;
  };
  auto goDown = [&](int i, int x) {
    int j = upper_bound(es[i].begin(), es[i].end(), P(x,INF))-es[i].begin()-1;
    if (j == -1) return x;
    if (x <= es[i][j].second) return es[i][j].first;
    return x;
  };

  auto solve = [&](int x, int y) {
    int ei = get(x);
    if (ei == -1) return INF;
    if (ce[ei].second >= y) return 1;
    int res = 1+1;
    for (int i = D-1; i >= 0; --i) {
      int ni = d[i][ei];
      if (ce[ni].second < y) {
        ei = ni;
        res += 1<<i;
      }
    }
    if (ce[d[0][ei]].second < y) return INF;
    return res;
  };

  rep(qi,q) {
    int si, sj, ti, tj;
    cin >> si >> sj >> ti >> tj;
    --si; --ti;
    if (sj > tj) swap(si,ti), swap(sj,tj);
    int ans = tj-sj;
    sj = goUp(si,sj);
    tj = goDown(ti,tj);
    if (sj >= tj) {
      if (si != ti) ans++;
    } else {
      ans++;
      ans += solve(sj,tj);
    }
    if (ans >= INF) ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}
