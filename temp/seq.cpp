int get_lis(vector<int> &a) {
	int N = a.size(); vector<int> dp(N, INF);
	for (int i = 0; i < N; ++i) *upper_bound(dp.begin(), dp.begin() + N, a[i]) = a[i];
	return lower_bound(dp.begin(), dp.begin() + N, INF) - dp.begin();
}

template<typename T>
pair<typename vector<T>::iterator, typename vector<T>::iterator > max_successive(vector<T> &a) {
  ll c = 1; auto f = a.begin(), t = a.begin();
  for (auto itr = a.begin(); itr != a.end(); itr++) { if (itr - a.begin() > 0 && *itr == *(itr - 1)) { c++; } else c = 1; if (c > t - f) { t = itr + 1; f = t - c; } }
  return make_pair(f, t);
}
