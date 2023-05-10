// キーに一括操作できる集合
template<class S, class F, class D, F(*op)(F, F), S(*inv)(S, F), F(*comp)(F, F)> struct bulkmap {
  map<S, D> data; F f;

  bulkmap() { f = F(); }
  size_t size() const { return data.size(); }
  void clear() { data.clear(); f = F(); }
  int count(S x) { return data.count(inv(x, f)); }
  typename map<S, D>::iterator begin() { return data.begin(); }
  typename map<S, D>::iterator end() { return data.end(); }
  typename map<S, D>::iterator find(S x) { return data.find(inv(x, f)); }
  typename map<S, D>::iterator erase(S x) { return data.erase(inv(x, f)); }
  inline D &operator[](const S x) { return data[inv(x, f)]; }

  void apply(F x) { f = comp(f, x); }
  void foreach(function<void(S, D)> g) { for(auto &&[k, v]: data) g(op(k, f), v); }
};

// ll op(ll x, ll f) { return x + f; }
// ll inv(ll x, ll f) { return x - f; }
using S = ll; using F = ll;
S op(S x, F f) { return x ^ f; }
S inv(S x, F f) { return x ^ f; }
F comp(F x, F f) { return x ^ f; }

bulkmap<S, F, ll, op, inv, comp> bs;

// 一括操作できる集合
// 値を一つ取りたい場合、bs.get(bs.find(x))としないといけないことに注意
template<class S, class F, F(*op)(F, F), S(*inv)(S, F), F(*comp)(F, F)> struct bulkset {
  set<S> data; F f;

  bulkset() { f = F(); }
  size_t size() const { return data.size(); }
  void clear() { data.clear(); f = F(); }
  typename set<S>::iterator begin() { return data.begin(); }
  typename set<S>::iterator end() { return data.end(); }
  typename set<S>::iterator find(S x) { return data.find(inv(x, f)); }
  typename set<S>::iterator erase(S x) { return data.erase(inv(x, f)); }

  pair<typename set<S>::iterator, bool> insert(S x) { return data.insert(inv(x, f)); }
  S get(typename set<S>::iterator it) { return op(*it, f); }

  void apply(F x) { f = comp(f, x); }
  void foreach(function<void(S)> g) { for(auto &&x: data) g(op(x, f)); }
};

using S = ll; using F = ll;
S op(S x, F f) { return x ^ f; }
S inv(S x, F f) { return x ^ f; }
F comp(F x, F f) { return x ^ f; }

using BS = bulkset<S, F, op, inv, comp>;
