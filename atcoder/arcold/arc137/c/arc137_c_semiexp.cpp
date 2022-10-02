#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N;
int A[303030];

map<set<int>, int> memo;

int solve(set<int> seq) {
	if (memo.count(seq)) return memo[seq];

	if (seq.size() - 1 == *--seq.end()) {
		return 1;
	}
	auto p = --seq.end();
	int lg = *p;
	seq.erase(p);

	for (int i = 0; i < lg; ++i) {
		if (seq.count(i) == 0) {
			auto seq2 = seq;
			seq2.insert(i);
			if (solve(seq2) == 1) return 0;
		}
	}
	return 1;
}

int main()
{
	// if (true) {
	// scanf("%d", &N);
	// for (int i = 0; i < N; ++i) scanf("%d", A + i);

	// if (A[N - 1] == A[N - 2] + 1 && A[N - 1] % 2 != N % 2) {
	// 	puts("Bob");
	// } else {
	// 	puts("Alice");
	// }
	// return 0;
	// }
	{
		const int MX = 15;
		for (int a = 0; a < MX; ++a) {
			for (int b = a + 1; b < MX; ++b) {
				for (int c = b + 1; c < MX; ++c) {
					for (int d = c + 1; d < MX; ++d) {
						if (solve({a, b, c})) printf("%d %d %d\n", a, b, c);
					}
				}
			}
		}
		return 0;
	}
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);

	set<int> s;
	for (int i = 0; i < N; ++i) s.insert(A[i]);
	printf("%d\n", solve(s));

	return 0;
}
