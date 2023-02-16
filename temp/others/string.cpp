// Reference:
// D. Gusfield,
// Algorithms on Strings, Trees, and Sequences: Computer Science and
// Computational Biology
template <class T> std::vector<int> z_algorithm(const std::vector<T>& s) {
  int n = int(s.size());
  if (n == 0) return {};
  std::vector<int> z(n);
  z[0] = 0;
  for (int i = 1, j = 0; i < n; i++) {
    int& k = z[i];
    k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
    while (i + k < n && s[k] == s[i + k]) k++;
    if (j + z[j] < i + z[i]) j = i;
  }
  z[0] = n;
  return z;
}

std::vector<int> z_algorithm(const std::string& s) {
  int n = int(s.size());
  std::vector<int> s2(n);
  for (int i = 0; i < n; i++) {
    s2[i] = s[i];
  }
  return z_algorithm(s2);
}

vs split(string str, char del) {
  int cur = 0; vs res;
  while (cur < str.size()) {
    auto to = str.find(del, cur); if (to == string::npos) to = str.size();
    res.pb(str.substr(cur, to - cur));
    cur = to + 1;
  }
  return res;
}

vl manacher(const string &_s, bool even = false) {
  string s = "";
  if (even) { for(int i = 0; i < (int)_s.size(); ++i) { s.pb('$'); s.pb(_s[i]); } s.pb('$'); } else s = _s;
  ll n = s.size();
  vl radius(n); int i = 0, j = 0;
  while(i < n) {
    while(i - j >= 0 && i + j < n && s[i - j] == s[i + j]) ++j;
    radius[i] = j;
    int k = 1;
    while(i - k >= 0 && i + k < n && k + radius[i - k] < j) {
      radius[i + k] = radius[i - k]; ++k;
    }
    i += k; j -= k;
  }
  if (even) { radius.erase(radius.begin()); radius.pop_back(); for(int i = 0; i < (int)radius.size(); ++i) --radius[i]; }
  return radius;
}
