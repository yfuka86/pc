#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// https://nyaannyaan.github.io/library/segment-tree/segment-tree-beats-abstract.hpp
template <typename Node>
struct Beats {
  int n, log;
  vector<Node> v;

  template <typename T>
  Beats(vector<T>& vc) {
    n = 1, log = 0;
    while (n < (int)vc.size()) n <<= 1, log++;
    v.resize(2 * n);
    for (int i = 0; i < (int)vc.size(); ++i) v[i + n] = Node(vc[i]);
    for (int i = n - 1; i; --i) _update(i);
  }

  template <typename T>
  void apply(int l, int r, T x) {
    if (l == r) return;
    l += n, r += n;
    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) _push(l >> i);
      if (((r >> i) << i) != r) _push((r - 1) >> i);
    }
    {
      int l2 = l, r2 = r;
      while (l < r) {
        if (l & 1) _apply(l++, x);
        if (r & 1) _apply(--r, x);
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }
    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l) _update(l >> i);
      if (((r >> i) << i) != r) _update((r - 1) >> i);
    }
  }

  template <typename F>
  void query(int l, int r, const F& f) {
    if (l == r) return;
    l += n, r += n;
    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) _push(l >> i);
      if (((r >> i) << i) != r) _push((r - 1) >> i);
    }
    while (l < r) {
      if (l & 1) f(v[l++]);
      if (r & 1) f(v[--r]);
      l >>= 1;
      r >>= 1;
    }
  }

 private:
  void _push(int i) { v[i].push(v[2 * i + 0], v[2 * i + 1]); }
  void _update(int i) { v[i].update(v[2 * i + 0], v[2 * i + 1]); }
  template <typename T>
  void _apply(int i, T x) {
    bool res = v[i].apply(x);
    if (i < n && res == false) {
      _push(i);
      _apply(i * 2 + 0, x);
      _apply(i * 2 + 1, x);
      _update(i);
    }
  }
};

using T = long long;
using U = pair<int, int>;
struct Node {
  T sm, val;
  int size;
  bool same;
  Node(T n = 0) : sm(n), val(n), size(1), same(true) {}

  void query2(T x) { sm = x * size, val = x, same = true; }
  void push(Node& l, Node& r) {
    if (same) l.query2(val), r.query2(val);
  }
  void update(Node& l, Node& r) {
    sm = l.sm + r.sm;
    val = l.val;
    size = l.size + r.size;
    same = l.same and r.same and l.val == r.val;
  }
  bool apply(U p) {
    if (p.first == 1) {
      return same ? (query2(val / p.second), true) : false;
    } else {
      return query2(p.second), true;
    }
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  vector<T> a(N);
  for (auto& x : a) cin >> x;
  Beats<Node> seg(a);
  for (int i = 0; i < Q; i++) {
    int cmd, L, R, x = -1;
    cin >> cmd >> L >> R;
    --L;
    if (cmd == 1) {
      cin >> x;
      seg.apply(L, R, make_pair(1, x));
    } else if (cmd == 2) {
      cin >> x;
      seg.apply(L, R, make_pair(2, x));
    } else {
      T ans = 0;
      seg.query(L, R, [&](Node& n) { ans += n.sm; });
      cout << ans << "\n";
    }
  }
}
