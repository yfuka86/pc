vvl cycle_decomposition(const vl& a) {
  const int n = a.size();
  vector<bool> visited(n); vvl res;
  for(int i = 0; i < n; i++) if (!visited[i]) {
    res.emplace_back();
    auto& vs = res.back();
    int v = i;
    do {
      visited[v] = true;
      vs.push_back(v);
      v = a[v];
    } while (v != i);
  }
  return res;
}
