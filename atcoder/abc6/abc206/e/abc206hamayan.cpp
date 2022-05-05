#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/
int L, R;
ll cnt[1010101];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> L >> R;

	rrep(g, 1010100, 2) {
		cnt[g] = 1LL * (R / g - (L - 1) / g) * (R / g - (L - 1) / g);
		int x = 2 * g;
		while (x <= R) {
			cnt[g] -= cnt[x];
			x += g;
		}
	}

	ll ans = 0;
	rep(g, 2, 1010101) {
		ans += cnt[g];
		if (L <= g && g <= R) {
			ans -= R / g - (L - 1) / g;
			ans -= R / g - (L - 1) / g;
			ans++;
		}
	}
	cout << ans << endl;
}





