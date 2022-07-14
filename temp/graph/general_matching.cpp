struct Edmonds {
	vector<vector<int>> g; int n, T;
	vector<int> mt, used, par, dsu, tm, Q;

	Edmonds() : g(), n(0), mt(), used(), par(), dsu(), tm(), T() {}
	Edmonds(int _n) {
		n = _n; g.clear(); g.resize(n);
		mt.assign(n, -1); used.assign(n, 0); par.assign(n, -1); dsu.assign(n, -1); tm.assign(n, 0); T = 1;
	}
	void addEdge(int v, int u) { g[v].push_back(u); g[u].push_back(v); }
	void clear() { mt.assign(n, -1); }
	int blossom(int v) { return (dsu[v] == -1 ? v : dsu[v] = blossom(dsu[v])); }
	void unite(int v, int u) {
		v = blossom(v); u = blossom(u);
		if (v == u) return; dsu[v] = u;
	}
	int lca(int v, int u) {
		T++;
		while(true) {
			if (v == -1 && u == -1) return -1;
			swap(v, u);
			if (v == -1) continue;
			v = blossom(v);
			if (tm[v] == T) return v;
			tm[v] = T;
			if (mt[v] != -1) v = par[mt[v]]; else v = -1;
		}
	}
	void shrinkBlossom(int v, int p) {
		while(v != p) {
			int u = mt[v]; int w = par[u];
			if (blossom(w) != p) par[w] = u;
			if (used[u] == 2) { used[u] = 1; Q.push_back(u); }
			if (used[w] == 2) { used[w] = 1; Q.push_back(w); }
			unite(v, u); unite(v, w);
			v = w;
		}
	}
	void alternateUp(int u) {
		while(u != -1) {
			int v = par[u]; int w = mt[v];
			mt[v] = u; mt[u] = v; u = w;
		}
	}
	int BFS() {
		for (int it = 0; it < (int)Q.size(); it++) {
			int v = Q[it];
			for (int u : g[v]) {
				if (mt[v] == u) continue;
				if (blossom(v) == blossom(u)) continue;
				if (used[u] == 2) continue;
				if (used[u] == 1) {
					int base = lca(v, u);
					if (base == -1) {
						int pv = mt[v], pu = mt[u];
						mt[v] = u; mt[u] = v;
						alternateUp(pv); alternateUp(pu);
						return 1;
					}
					if (blossom(v) != base) par[v] = u;
					if (blossom(u) != base) par[u] = v;
					shrinkBlossom(v, base);
					shrinkBlossom(u, base);
				} else if (mt[u] == -1) {
					par[u] = v;
					alternateUp(u);
					return 1;
				} else {
					par[u] = v; used[u] = 2;
					u = mt[u]; used[u] = 1;
					Q.push_back(u);
				}
			}
		}
		return 0;
	}
	int tryIncrease() {
		Q.clear();
		for (int i = 0; i < n; i++) {
			used[i] = 0; par[i] = -1; dsu[i] = -1;
		}
		int RES = 0;
		for (int v = 0; v < n; v++) {
			if (mt[v] != -1) continue;
			bool fnd = false;
			for (int u : g[v]) {
				if (mt[u] == -1) {
					fnd = true; RES++;
					mt[v] = u; mt[u] = v;
					break;
				}
			}
			if (fnd) continue;
			used[v] = 1; Q.push_back(v);
		}
		return RES + BFS();
	}
	int increaseMatching() {
		int res = 0;
		while(true) {
			int cur = tryIncrease();
			if (cur == 0) break;
			res += cur;
		}
		return res;
	}
} E;
