// 双対セグ木
// Dが保持するもの、opが操作、Sが単位元
// updateはセグ木の形で更新
// queryはその区間を含むものを広げながら遡る
template <class D, class op, class S>
struct StarrySkyTree {
  int N, p2; vector<vector<D>> data;

  StarrySkyTree(int _N, D d) : N(_N) {
    p2 = ceil_pow2(N);
    data = vector<vector<D>>(p2 + 1);
    for(int b = 0; b <= p2; b++) data[b] = vector<D>(1 << (p2 - b), d);
  }

  template <class UP>
  void update(const UP &update, int l, int r, op x) {
    assert(0 <= l && r <= N && l <= r);
    rep(b, p2 + 1) {
      if (l & 1) update(data[b][l++], x);
      if (r & 1) update(data[b][--r], x);
      l >>= 1;
      r >>= 1;
      if (l == r) break;
    }
  }

  template <class M>
  void query(const M &merge, int x, S &e) {
    assert(0 <= x && x < N);
    rep(b, p2 + 1) {
      merge(e, data[b][x]);
      x >>= 1;
    }
  }
};

// using D = ll;
// using op = ll;
// using S = ll;

// // 対象ブロック d, 作用素 x
// auto update = [&](D &d, op x) {
// };
// // 作用素 x, 対象ブロック d
// auto merge = [&](S &x, D &d) {
// };
