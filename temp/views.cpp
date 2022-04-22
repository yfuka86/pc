
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
  vector<ll> ranges;
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
    auto litr = lower_bound(all(ranges), l); if (litr == ranges.end()) { ranges.pb(l); ranges.pb(r); return; }

    if ((litr - ranges.begin()) % 2 == 0) { litr = ranges.insert(litr, l); litr++; }
    auto ritr = upper_bound(all(ranges), r); ranges.insert(ritr, r);

    if (litr == ranges.end()) return;
    auto itr = ranges.erase(litr, ritr);
    if (ranges.size() % 2 == 1) ranges.erase(itr);
  }

  bool include(ll at) {
    auto itr = upper_bound(all(ranges), at);
    if (itr == ranges.end()) return false;
    return (itr - ranges.begin()) % 2 == 1;
  }
};
