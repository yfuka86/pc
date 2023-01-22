// https://nyaannyaan.github.io/library/rbst/lazy-reversible-rbst.hpp

template <typename T, typename E>
struct LazyReversibleRBSTNode {
  typename RBSTBase<LazyReversibleRBSTNode>::Ptr l, r;
  T key, sum;
  E lazy;
  int cnt;
  bool rev;

  LazyReversibleRBSTNode(const T &t = T(), const E &e = E())
      : l(), r(), key(t), sum(t), lazy(e), cnt(1), rev(false) {}
};

template <typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),
          T (*ts)(T)>
struct LazyReversibleRBST : RBSTBase<LazyReversibleRBSTNode<T, E>> {
  using Node = LazyReversibleRBSTNode<T, E>;
  using base = RBSTBase<LazyReversibleRBSTNode<T, E>>;
  using base::merge;
  using base::split;
  using typename base::Ptr;

  LazyReversibleRBST() = default;

  void toggle(Ptr t) {
    swap(t->l, t->r);
    t->sum = ts(t->sum);
    t->rev ^= true;
  }

  T fold(Ptr &t, int a, int b) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    auto ret = sum(y.first);
    t = merge(x.first, merge(y.first, y.second));
    return ret;
  }

  void reverse(Ptr &t, int a, int b) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    toggle(y.first);
    t = merge(x.first, merge(y.first, y.second));
  }

  void apply(Ptr &t, int a, int b, const E &e) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    propagate(y.first, e);
    t = merge(x.first, merge(y.first, y.second));
  }

 protected:
  inline T sum(const Ptr t) const { return t ? t->sum : T(); }

  Ptr update(Ptr t) override {
    push(t);
    t->cnt = 1;
    t->sum = t->key;
    if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);
    if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);
    return t;
  }

  void push(Ptr t) override {
    if (t->rev) {
      if (t->l) toggle(t->l);
      if (t->r) toggle(t->r);
      t->rev = false;
    }
    if (t->lazy != E()) {
      if (t->l) propagate(t->l, t->lazy);
      if (t->r) propagate(t->r, t->lazy);
      t->lazy = E();
    }
  }

  void propagate(Ptr t, const E &x) {
    t->lazy = h(t->lazy, x);
    t->key = g(t->key, x);
    t->sum = g(t->sum, x);
  }
};

/**
 * @brief 遅延伝搬反転可能乱択平衡二分木
 * @docs docs/rbst/lazy-reversible-rbst.md
 */
