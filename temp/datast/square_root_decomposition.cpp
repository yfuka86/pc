// 列の平方分割
template <class S, class T>
struct SquareRootDecomposition {
  struct Block {
    int id, l, r, sz; Block() = default;
    Block(int _i, int _l, int _r) : id(_i), l(_l), r(_r) { sz = r - l; }
  };
  int N, B; vector<Block> bl;

  SquareRootDecomposition(int _N, int _B) : N(_N), B(_B) {
    bl.resize(N / B + 1);
    for (int i = 0; i <= N / B; ++i) { bl[i] = Block(i, i * B, min((i + 1) * B, N)); }
  }
  int size() const { return bl.size(); }

  template <class UP, class UA>
  void update(const UP &update_part, const UA &update_all, int l, int r, S x) {
    assert(0 <= l && r <= N && l <= r);
    if (l / B == r / B) {
      update_part(bl[l / B], l, r, x);
    } else {
      if (l % B) update_part(bl[l / B], l, (l / B + 1) * B, x);
      for (int i = ceil(l, B); i < r / B; i++) update_all(bl[i], x);
      if (r % B) update_part(bl[r / B], (r / B) * B, r, x);
    }
  }

  template <class QP, class QA, class M>
  T query(const QP &query_part, const QA &query_all, const M &merge, int l, int r, T e) {
    assert(0 <= l && r <= N && l <= r);
    if (l / B == r / B) return query_part(bl[l / B], l, r);
    T ret = e;
    if (l % B) ret = merge(ret, query_part(bl[l / B], l, (l / B + 1) * B));
    for (int i = ceil(l, B); i < r / B; i++) ret = merge(ret, query_all(bl[i]));
    if (r % B) ret = merge(ret, query_part(bl[r / B], (r / B) * B, r));
    return ret;
  }
};

// queryの動作はまだ未検証
SquareRootDecomposition<ll, ll> seg(n, b);
// ブロック数
seg.size()
// 対象ブロック b[b.id], 範囲 [l, r), 作用素 x
auto update_part = [&](auto b, ll l, ll r, ll x) {
};
// 対象ブロック b[b.id], 作用素 x, ( 範囲[b.l, b.r) )
auto update_all = [&](auto b, ll x) {
};
// 対象ブロック b[b.id], 範囲 [l, r)
auto query_part = [&](auto b, ll l, ll r) {
};
// 対象ブロック b[b.id], 範囲 [b.l, b.r)
auto query_all = [&](auto b) {
};
