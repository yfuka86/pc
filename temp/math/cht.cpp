struct Node {
	long double l, r; long long a, b;
};
bool operator<(const Node &a1, const Node &a2) {
	if (a1.l < a2.l) return true;
	return false;
}

class ConvexHullTrick {
public:
	vector<Node> U;
	void init() {
		U.push_back(Node{ -1e9, 1e9, 0, (1LL << 43) });
	}
	long double cross_point(Node E, Node F) {
		if (E.a > F.a) swap(E, F);
		long double D1 = 2.0L * (F.a - E.a);
		long double D2 = F.b - (E.b + (F.a - E.a) * (F.a - E.a));
		return 1.0L * F.a + 1.0L * D2 / D1;
	}
	void add(long long a, long long b) {
		while (U.size() >= 1) {
			Node E = U[U.size() - 1];
			long double T = cross_point(E, Node{ -1e9, 1e9, a, b });

			if (T < E.l) {
				U.pop_back();
			}
			else {
				U[U.size() - 1].r = T;
				U.push_back(Node{ T, 1e9, a, b });
				break;
			}
		}
		if (U.size() == 0) {
			U.push_back(Node{ -1e9, 1e9, a, b });
		}
	}
	long long query(long long T) {
		Node BASE = Node{ 1.0L * T, 1.0L * T, 0LL, 0LL };
		int pos1 = lower_bound(U.begin(), U.end(), BASE) - U.begin();
		pos1--;
		return U[pos1].b + (T - U[pos1].a) * (T - U[pos1].a);
	}
};
