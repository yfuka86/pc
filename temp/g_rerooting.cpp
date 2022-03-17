template <typename Cost, typename Data, Data (*merge)(Data, Data), Data (*e)(),
          Data (*leaf)(), Data (*apply)(Data, int, int, Cost)>
struct Rerooting : Graph<Cost> {
  vector<Data> dp, memo;
  Rerooting(int n) : Graph<Cost>::Graph(n) {}
  vector<Data> run() {
    memo.resize((*this).size(), e());
    dp.resize((*this).size());
    dfs1(0, -1);
    dfs2(0, -1, e());
    return dp;
  }
  void dfs1(int c, int p) {
    bool upd = false;
    for (Edge<Cost> &d : (*this)[c]) {
      if (d == p) continue;
      dfs1(d, c);
      upd = true;
      memo[c] = merge(memo[c], apply(memo[d], d, c, d.cost));
    }
    if (!upd) memo[c] = leaf();
  }
  void dfs2(int c, int p, const Data &val) {
    vector<Data> ds{val};
    for (Edge<Cost> &d : (*this)[c]) {
      if (d == p) continue;
      ds.push_back(apply(memo[d], d, c, d.cost));
    }
    int n = ds.size(), idx = 1;
    vector<Data> head(n + 1, e()), tail(n + 1, e());
    for (int i = 0; i++ < n;) head[i] = merge(head[i - 1], ds[i - 1]);
    for (int i = n; i-- > 0;) tail[i] = merge(tail[i + 1], ds[i]);
    dp[c] = head[n];
    for (Edge<Cost> &d : (*this)[c]) {
      if (d == p) continue;
      Data sub = merge(head[idx], tail[idx + 1]);
      dfs2(d, c, apply(sub, c, d, d.cost));
      idx++;
    }
  }
};


using Data = long long;
using Cost = long long;
Data merge(Data a, Data b) { return max(a, b); }
Data e() { return 0; }
Data leaf() { return 0; }
Data apply(Data a, int c, int, Cost w) { return max<Data>(a, D[c]) + w; }
Rerooting<Cost, Data, merge, e, leaf, apply> g(N);
