// https://atcoder.jp/contests/abc223/tasks/abc223_h
// 動画解説: D次元の基底をとって更新していく
template<typename T = ll>
struct MaxBasis {
  static const int D = 60; using BS = bitset<D>;
  vector<BS> b, s; vector<T> w;
  MaxBasis(): b(D), s(D), w(D) {}
  void add(BS x, T nw) {
    BS ns;
    rep(i, D) if (x[i] && b[i][i]) { x ^= b[i]; ns ^= s[i]; }
    if (x.count()) {
      int j = -1;
      rep(i, D) if (x[i]) { j = i; break; }
      ns[j] = 1;
      { // 基底を追加した時の各要素の更新作業
        rep(i, D) if (b[i][j]) { b[i] ^= x; s[i] ^= ns; }
        b[j] = x; s[j] = ns; w[j] = nw;
      }
      return;
    }
    T mi = numeric_limits<T>::max(); int j = -1;
    rep(i, D) if (ns[i] && chmin(mi, w[i])) j = i;
    if (j == -1) return;
    { // 追加しなくてよい場合の交換
      w[j] = nw; ns[j] = 0;
      rep(i, D) if (s[i][j]) s[i] ^= ns;
    }
  }
  T get_min(BS x) {
    BS ns;
    // 基底によって表す
    rep(i, D) if (x[i] && b[i][i]) { x ^= b[i]; ns ^= s[i]; }
    // 表せない場合
    if (x.count()) return numeric_limits<T>::min();
    // 表せる場合
    T res = numeric_limits<T>::max();
    if (!ns.count()) return res;
    rep(i, D) if (ns[i]) chmin(res, w[i]);
    return res;
  }
  void dump() { rep(i, D) debug(b[i], s[i]); debug(w); }
};


// XOR 基底を求める
//   - O(B (N + logB))   B はビット長
//   - 掃き出し法と同じように MSB の降順にする（不要なら消す）
template<class T> struct xor_basis {
  vector<T> basis;
  bool add(T a) {
    for (const T& b: basis) { a = min(a, a ^ b); }
    if (a) { basis.push_back(a); sort(basis.rbegin(), basis.rend()); return true; } else return false;
  }
  bool presentable(T a) {
    for (const T& b: basis) { a = min(a, a ^ b); }
    if (a) return false; else return true;
  }
  // fromをマージ
  void merge(xor_basis<T> &from) { for(const T& b: from.basis) add(b); }
  T get_max(T sum = 0) { for(const T& b: basis) chmax(sum, sum ^ b); return sum; }
  T get_min(T sum = 0) { for(const T& b: basis) chmin(sum, sum ^ b); return sum; }
};
