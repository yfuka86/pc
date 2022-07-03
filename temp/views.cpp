
// 1回O(1)で擬似回転するベクタ rotateの第二引数と同じ(右シフトならsize-1、左シフトなら1)
template<typename T>
struct RotateVector {
  __uint128_t offset = 0; vector<T> vec;
  RotateVector(vector<T> &v) { vec = v; }
  void rotate(ll a) { offset += a; }
  T &operator[](int k) { return vec[(k + offset) % vec.size()]; }
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
