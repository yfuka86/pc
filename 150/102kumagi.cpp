
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
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define vi vector<int>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;

int bitcount(int n) { int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;}
template<typename T>
void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T>
void coutmatrix(vector<vector<T> >& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} };
template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

void comp(vector<int>&a){
  set<int>s(a.begin(),a.end()); map<int,int>d;
  int cnt=0; for(int x:s)d[x]=cnt++; for(int&x:a)x=d[x];
}

int main()
{
  int n;
  cin >> n;
  vector<int> heights(n), arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    heights[i] = arr[i];
  }
  sort(heights.begin(), heights.end());
  heights.erase(unique(heights.begin(), heights.end()), heights.end());
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    auto off = lower_bound(heights.begin(), heights.end(), arr[i]);
    size_t diff = distance(heights.begin(), off);
    ans[i] = diff;
  }
  for (auto& elm : ans) {
    cout << elm << "\n";
  }
}


