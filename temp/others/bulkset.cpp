template<class S, class F, class D, S(*op)(S, F), S(*inv)(S, F)> struct bulkset {
  map<S, D> data; F f;

  bulkset() { f = F(); }
  bool count(S x) { return data.count(inv(x, f)); }
  typename map<S, D>::iterator begin() { return data.begin(); }
  typename map<S, D>::iterator end() { return data.end(); }
  typename map<S, D>::iterator find(S x) { return data.find(x); }
  typename map<S, D>::iterator erase(S x) { return data.erase(inv(x, f)); }
  inline D &operator[](const S x) { return data[inv(x, f)]; }

  void apply(F x) { f = op(f, x); }
  void foreach(function<void(S, D)> g) { for(auto &&[k, v]: data) g(op(k, f), v); }
};

// ll op(ll x, ll f) { return x + f; }
// ll inv(ll x, ll f) { return x - f; }

ll op(ll x, ll f) { return x ^ f; }
ll inv(ll x, ll f) { return x ^ f; }
bulkset<ll, ll, ll, op, inv> bs;
