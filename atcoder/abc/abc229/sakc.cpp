#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (ll i=(ll)from; i<(ll)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (ll i=(ll)N-1; i>=0; i--)
#define popcount __builtin_popcount

const ll LLINF = pow(2,61)-1;
const ll INF = pow(2,30)-1;

ll gcd(ll a, ll b) { if (a<b) swap(a,b); return b==0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

struct cheese {
  ll A, B;
  bool operator> (const cheese &x) const { return A>x.A; }
};

int main() {
  ll N, W; cin >> N >> W;
  vector<cheese> c(N); rep(i,N) cin >> c[i].A >> c[i].B;
  sort(all(c), greater<cheese>());
  // rep(i,N) cout << c[i].A << " " << c[i].B << endl;

  ll result = 0;
  rep(i,N) {
    ll x = min(W, c[i].B);
    result += c[i].A * x;
    W -= x;
    if (!W) break;
  }
  cout << result << endl;
  return 0;
}
