// 中央値を管理するデータ構造
//   - size()   : O(1)
//   - empty()  : O(1)
//   - insert() : O(log N)
//   - erase()  : O(log N)
//   - get()  : O(1)
//   - query()  : O(1)
template <class T = ll>
struct Median {
  public:
  Median() {}

  // x を追加する
  //   - O(log N)
  void insert(const T& x) {
    if (empty()) { _size = 1; c1 = c2 = x; return; }

    if (_size & 1) {  // 奇数個
      assert(c1 == c2);
      if (x <= c1) {
        _insert_R(c2);
        _insert_L(x);
        c1 = *L.rbegin();
      } else {
        _insert_L(c1);
        _insert_R(x);
        c2 = *R.begin();
      }
    } else {  // 偶数個
      if (x <= c1) {
        _insert_L(x);
        c1 = c2 = *L.rbegin();
        _erase_L(prev(L.end()));
      } else {
        _insert_R(x);
        c1 = c2 = *R.begin();
        _erase_R(R.begin());
      }
    }
    _size++;
  }

  // x を削除して、その成否を返す
  //   - O(log N)
  bool erase(const T& x) {
    if (empty()) { return false; }
    if (_size == 1) { _size = 0; c1 = c2 = 0; return true; }

    if (_size & 1) {  // 奇数個
      assert(c1 == c2);
      if (x < c1) {
        if (not _try_erase_L(x)) { return false; }
        _insert_L(c1);
        c2 = *R.begin();
      } else if (c1 < x) {
        if (not _try_erase_R(x)) { return false; }
        _insert_R(c2);
        c1 = *L.rbegin();
      } else {
        c1 = *L.rbegin();
        c2 = *R.begin();
      }
    } else {  // 偶数個
      if (x <= c1) {
        if (not _try_erase_L(x)) { return false; }
        c1 = c2 = *R.begin();
        _erase_R(R.begin());
      } else if (c2 <= x) {
        if (not _try_erase_R(x)) { return false; }
        c1 = c2 = *L.rbegin();
        _erase_L(prev(L.end()));
      } else {
        return false;
      }
    }
    _size--;
    return true;
  }

  // 中央値を返す
  //   - O(1)
  //   - floor((N+1)/2) 番目に小さい要素を返す
  T get_l() const noexcept { return c1; }

  // 中央値を返す
  //   - O(1)
  //   - ceil((N+1)/2) 番目に小さい要素を返す
  T get_r() const noexcept { return c2; }

  // 「差の絶対値の総和」の最小値を返す
  //  - O(1)
  //  - min{Σ|x - a_i|}
  ll query() const noexcept {
    ll m = get_l();
    ll res = 0;
    res += (ll)L.size() * m - SL;
    res += SR - (ll)R.size() * m;
    return res;
  }

  // 要素数を返す
  //   - O(1)
  int size() const noexcept { return _size; }

  // 要素数が 0 か否かを返す
  //   - O(1)
  bool empty() const noexcept { return (_size == 0); }

  private:
  multiset<T> L, R;
  T c1 = 0, c2 = 0;
  ll SL = 0, SR = 0;
  int _size = 0;

  void _insert_L(const T& x) { SL += x; L.insert(x); }
  void _insert_R(const T& x) { SR += x; R.insert(x); }
  void _erase_L(const class multiset<T>::iterator& it) { SL -= *it; L.erase(it); }
  void _erase_R(const class multiset<T>::iterator& it) { SR -= *it; R.erase(it); }
  bool _try_erase_L(const T& x) {
    auto it = L.find(x);
    if (it == L.end()) { return false; }
    else { _erase_L(it); return true; }
  }
  bool _try_erase_R(const T& x) {
    auto it = R.find(x);
    if (it == R.end()) { return false; }
    else { _erase_R(it); return true; }
  }
};
