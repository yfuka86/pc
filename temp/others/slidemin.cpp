struct SlideMin {
  deque<LP> q;
  SlideMin() {}
  void push(ll i, ll x) {
    while (q.size() && q.back().second >= x) {
      q.pop_back();
    }
    q.emplace_back(i,x);
  }
  ll get(ll l) { // l <= i
    while (q.size() && q.front().first < l) {
      q.pop_front();
    }
    assert(q.size());
    return q.front().second;
  }
};
