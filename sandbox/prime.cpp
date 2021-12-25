#pragma GCC optimize("Ofast")
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
#include <climits>
#include <bitset>
#include <numeric>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define per1(i,n) for(int i=(int)(n);i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=(int)(n);i++)
#define all(v) (v).begin(),(v).end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vi;
typedef vector<ll> vl;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();
const ll mod = 1000000007;

int bitcount(int n) { int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;}
void comp(vector<int>&a){ vector<int> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T>
void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T>
void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} };
template<typename K, typename V>
void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

vector<int> primes_below(const int N) {
  vector<bool> is_prime(N + 1, true);
  for(int i = 2; i * i <= N; i++) {
    if ((i > 2 && i % 2 == 0) || !is_prime[i])  continue;
    for(int j = i * i; j <= N; j += i) is_prime[j] = false;
  }
  vector<int> ret;
  for(int i = 2; i <= N; i++) if (is_prime[i]) ret.emplace_back(i);
  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vi p = primes_below(10000000);
  cout << p.size();
}

