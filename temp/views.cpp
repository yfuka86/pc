// 1回O(1)で擬似回転するベクタ rotateの第二引数と同じ(右シフトならsize-1、左シフトなら1)
template<typename T>
struct RotateVector {
  __uint128_t offset = 0; vector<T> vec;
  RotateVector(vector<T> &v) { vec = v; }
  void rotate(ll a) { offset += a; }
  T &operator[](int k) { return vec[(k + offset) % vec.size()]; }
};

// 回転と反転ができる正方行列
template<typename T>
struct view2d {
  int n, angle = 0, mirror = 0; vector<vector<T>> a;
  view2d(int _n): n(_n) { a.assign(n, vector<T>(n, T(0))); }

  void rotate() { angle++; angle %= 4; }
  void revx() { mirror = 1 - mirror; if (angle == 1 || angle == 3) { angle += 2; angle %= 4; } }
  void revy() { mirror = 1 - mirror; if (angle == 0 || angle == 2) { angle += 2; angle %= 4; } }

  T& get(ll x, ll y) {
    rep(i, angle) {
      ll nx = n - 1 - y, ny = x;
      x = nx; y = ny;
    }
    if (mirror) x = n - 1 - x;
    return a[x][y];
  }
};

// ビット列を反転のインデックスのみで保持したいもの
struct Bitseq {
  vl ranges;
  Bitseq() : ranges(0) {}

  void invert(ll l, ll r) {
    assert(l < r);
    auto litr = lower_bound(all(ranges), l);
    if (litr == ranges.end()) { ranges.pb(l); } else {
      if (*litr == l) ranges.erase(litr); else ranges.insert(litr, l);
    }
    auto ritr = lower_bound(all(ranges), r);
    if (ritr == ranges.end()) { ranges.pb(r); } else {
      if (*ritr == r) ranges.erase(ritr); else ranges.insert(ritr, r);
    }
  }

  void on(ll l, ll r) {
    assert(l < r);
    ll li = lbs(ranges, l);
    ll ri = ubs(ranges, r);
    if (!(ri & 1)) ranges.insert(ranges.begin() + ri, r);
    if (!(li & 1)) { ranges.insert(ranges.begin() + li, l); ri++; li++; }

    if (li != ri) ranges.erase(ranges.begin() + li, ranges.begin() + ri);
    // coutarray(ranges);
    assert(!(ranges.size() & 1));
  }

  bool include(ll at) {
    auto itr = upper_bound(all(ranges), at);
    if (itr == ranges.end()) return false;
    return (itr - ranges.begin()) % 2 == 1;
  }
};

// レンジの和集合管理
struct Rngset {
  map<ll, ll> ranges;
  Rngset() : ranges() {}

  void on(ll l, ll r) {
    assert(l < r);
    auto lt = ranges.lower_bound(l);
    auto rt = ranges.upper_bound(r);
    if (lt != ranges.begin() && l <= prev(lt)->se) { l = prev(lt)->fi; lt--; }
    if (rt != ranges.begin() && r <= prev(rt)->se) { r = prev(rt)->se; }
    while(lt != rt) { lt = ranges.erase(lt); }
    ranges[l] = r;
  }
};
