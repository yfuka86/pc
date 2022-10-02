#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#include <limits>
#include <bitset>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = numeric_limits<int>::max();

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }

int main()
{
  int N;
  cin >> N;

  rep(i, N) {

  }
}


void Nimk(int N, int K, vector<int>& pile) {
	vector< vector<int> > bin(N, vector<int>(30, 0)); // 2次元配列

	for (int i = 0; i < N; i++) { //pile[i]について、2進数に展開する
		int twopow = 1; // 2のべき乗
		for (int x = 0; x < 30; x++) {
			if (twopow & pile[i])// 2^xにくっつく数は0か1か
				bin[i][x] = 1;
			else
				bin[i][x] = 0;
			twopow = twopow * 2;
		}
	}

	vector<int> digitsum(N, 0); // 桁ごとの和

	for (int x = 0; x < 30; x++) {// 桁xについて
		for (int i = 0; i < N; i++) {
			digitsum[x] = digitsum[x] + bin[i][x];
		}
	}

	int win = 0; // 負けを0、勝ちを1とする
	for (int x = 0; x < 30; x++) {
		if (digitsum[x] % (K + 1) != 0) {
			// 桁の値が0ではないときは勝ちのポジション、grundy数が0でないことが確定する
			win = 1;
		}
	}

	if (win == 1) { // 先手の勝ち
		cout << "Alice" << endl;
	}
	else { // 先手の負け
		cout << "Bob" << endl;
	}

}
