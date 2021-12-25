int lcs(string &s1, string &s2){
  vector<vector<int> > dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
  function<int(int, int)> rec = [&](int m, int n) -> int {
    if (dp[m][n] != -1) return dp[m][n];
    if (m == 0 || n == 0) return dp[m][n] = 0;
    if (s1[m - 1] == s2[n - 1]) return dp[m][n] = rec(m - 1, n - 1) + 1;
    return max(rec(m, n - 1), rec(m - 1, n));
  };
  return rec(s1.size(), s2.size());
}

// Reference:
// D. E. Knuth, J. H. Morris, V. R. Pratt
// Fast pattern matching in strings
template <class T> std::vector<int> kmp(const std::vector<T>& s) {
  int n = int(s.size());
  if (n == 0) return {};
  std::vector<int> pi(n);
  pi[0] = -1;
  for (int i = 1, j = -1; i < n; i++) {
    while (j >= 0 && s[i] != s[j+1]) j = pi[j];
    if (s[i] == s[j+1]) ++j;
    pi[i] = j;
  }
  return pi;
}

std::vector<int> kmp(const std::string& s) {
  int n = int(s.size());
  std::vector<int> s2(n);
  for (int i = 0; i < n; i++) {
    s2[i] = s[i];
  }
  return kmp(s2);
}
