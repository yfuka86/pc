#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> t(q), a(q), b(q), c(q);
  vector<vector<int>> subt(q);
  vector latest(n, pair(-1, 0));
  vector<long long> ans;
  for (int i = 0; i < q; ++i) {
    cin >> t[i];
    if (t[i] == 1) {
      cin >> a[i] >> b[i] >> c[i];
      a[i] -= 1;
    } else if (t[i] == 2) {
      cin >> a[i] >> b[i];
      a[i] -= 1;
      latest[a[i]] = pair(i, b[i]);
    } else {
      cin >> a[i] >> b[i];
      a[i] -= 1;
      const auto& [j, x] = latest[a[i]];
      const int id = ans.size();
      ans.emplace_back(x);
      c[i] = id;
      if (j >= 0) {
        subt[j].push_back(i);
      }
    }
  }
  atcoder::fenwick_tree<long long> fen(m + 1);
  for (int i = 0; i < q; ++i) {
    if (t[i] == 1) {
      fen.add(a[i], c[i]);
      fen.add(b[i], -c[i]);
    } else if (t[i] == 2) {
      for (const int j : subt[i]) {
        ans[c[j]] -= fen.sum(0, b[j]);
      }
    } else {
      ans[c[i]] += fen.sum(0, b[i]);
    }
  }
  for (const long long x : ans) {
    cout << x << '\n';
  }
  return 0;
}
