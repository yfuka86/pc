void enum_check(ll N, ll from, ll to, function<bool(vl&)> check) { // size, [from, to)
  to--; vl st(N, from);
  while (1) {
    assert(st.size() == N); if (!check(st)) break;
    while (st.size() && st.back() == to) st.pop_back(); if (st.size() == 0) break;
    st.back()++; while (st.size() < N) st.pb(from);
  }
}
