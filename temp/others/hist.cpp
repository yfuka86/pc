
// 幅を持つ増加列のsum
// -で与えると減少列になる
// 増加だとその時点のminを与えると全てがならされる
// 減少だとその時点のmaxを与えると全てが引き上がる
template <class T> struct Hist {
  stack<pair<int, T>> st;
  T tot;
  Hist(T e = 0) { tot = e; }
  void add(int h, T w) {
    while (!st.empty() && st.top().first <= h) {
      auto [nh, nw] = st.top();
      tot -= nw * nh;
      w += nw;
      st.pop();
    }
    tot += w * h;
    st.emplace(h, w);
  }
};
