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
