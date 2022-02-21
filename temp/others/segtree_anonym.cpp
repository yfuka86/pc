/* RMQ：[0,n-1] について、区間ごとの最小値を管理する構造体
  set(int i, T x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
  update(i,x): i 番目の要素を x に更新。O(log(n))
  query(a,b): [a,b) での最小の要素を取得。O(log(n))
  find_rightest(a,b,x): [a,b) で x以下の要素を持つ最右位置を求める。O(log(n))
  find_leftest(a,b,x): [a,b) で x以下の要素を持つ最左位置を求める。O(log(n))
*/
template <typename T>
struct RMQ {
  const T e = numeric_limits<T>::max();
  function<T(T, T)> fx = [](T x1, T x2) -> T { return min(x1, x2); };
  int n;
  vector<T> dat;
  RMQ(int n_) : n(), dat(n_ * 4, e) {
    int x = 1;
    while (n_ > x) {
      x *= 2;
    }
    n = x;
  }
  void set(int i, T x) { dat[i + n - 1] = x; }
  void build() {
    for (int k = n - 2; k >= 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
  }
  void update(int i, T x) {
    i += n - 1;
    dat[i] = x;
    while (i > 0) {
      i = (i - 1) / 2;  // parent
      dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
  }
  // the minimum element of [a,b)
  T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
  T query_sub(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) {
      return e;
    } else if (a <= l && r <= b) {
      return dat[k];
    } else {
      T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
      return fx(vl, vr);
    }
  }
  int find_rightest(int a, int b, T x) { return find_rightest_sub(a, b, x, 0, 0, n); }
  int find_leftest(int a, int b, T x) { return find_leftest_sub(a, b, x, 0, 0, n); }
  int find_rightest_sub(int a, int b, T x, int k, int l, int r) {
    if (dat[k] > x || r <= a || b <= l) {  // 自分の値がxより大きい or [a,b)が[l,r)の範囲外ならreturn a-1
      return a - 1;
    } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
      return (k - (n - 1));
    } else {
      int vr = find_rightest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
      if (vr != a - 1) {  // 右の部分木を見て a-1 以外ならreturn
        return vr;
      } else {  // 左の部分木を見て値をreturn
        return find_rightest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
      }
    }
  }
  int find_leftest_sub(int a, int b, T x, int k, int l, int r) {
    if (dat[k] > x || r <= a || b <= l) {  // 自分の値がxより大きい or [a,b)が[l,r)の範囲外ならreturn b
      return b;
    } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
      return (k - (n - 1));
    } else {
      int vl = find_leftest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
      if (vl != b) {  // 左の部分木を見て b 以外ならreturn
        return vl;
      } else {  // 右の部分木を見て値をreturn
        return find_leftest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
      }
    }
  }
};

/* SegTreeLazyProportional<X,M>(n,fx,fa,fm,fp,ex,em): モノイド(集合X, 二項演算fx,fa,fm,p 単位元ex,em)についてサイズnで構築
    set(int i, X x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b):  [a,b) 全てにfxを作用させた値を取得。O(log(n))
*/
template <typename X, typename M>
struct SegTreeLazyProportional {
    using FX = function<X(X, X)>;
    using FA = function<X(X, M)>;
    using FM = function<M(M, M)>;
    using FP = function<M(M, int)>;
    int n;
    FX fx;
    FA fa;
    FM fm;
    FP fp;
    const X ex;
    const M em;
    vector<X> dat;
    vector<M> lazy;
    SegTreeLazyProportional(int n_, FX fx_, FA fa_, FM fm_, FP fp_, X ex_, M em_)
        : n(), fx(fx_), fa(fa_), fm(fm_), fp(fp_), ex(ex_), em(em_), dat(n_ * 4, ex), lazy(n_ * 4, em) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }
    void set(int i, X x) { dat[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }
    /* lazy eval */
    void eval(int k, int len) {
        if (lazy[k] == em) return;  // 更新するものが無ければ終了
        if (k < n - 1) {            // 葉でなければ子に伝搬
            lazy[k * 2 + 1] = fm(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = fm(lazy[k * 2 + 2], lazy[k]);
        }
        // 自身を更新
        dat[k] = fa(dat[k], fp(lazy[k], len));
        lazy[k] = em;
    }
    void update(int a, int b, M x, int k, int l, int r) {
        eval(k, r - l);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] = fm(lazy[k], x);
            eval(k, r - l);
        } else if (a < r && l < b) {                     // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            dat[k] = fx(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    void update(int a, int b, M x) { update(a, b, x, 0, 0, n); }
    X query_sub(int a, int b, int k, int l, int r) {
        eval(k, r - l);
        if (r <= a || b <= l) {  // 完全に外側の時
            return ex;
        } else if (a <= l && r <= b) {  // 完全に内側の時
            return dat[k];
        } else {  // 一部区間が被る時
            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }
    X query(int a, int b) { return query_sub(a, b, 0, 0, n); }
};
