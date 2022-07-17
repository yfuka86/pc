#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

struct segcover {
	map<pair<ll,ll>,ll> sg;
	ll L_,R_;
	void init(ll L,ll R) {
		sg[{L-1,L-1}]=-1;
		sg[{R+1,R+1}]=-1;
		sg[{L,R}]=0;
		L_=L-1; R_=R+1;
	}
	void add(ll l,ll r,ll id,function<void(ll,ll,ll)>delseg=[](ll l,ll r,ll id) {},
		function<void(ll,ll,ll)> addseg=[](ll l,ll r,ll id) {}) {
		auto split=[&](ll p) {
			auto pl=--sg.lower_bound({p,L_});
			if (pl->fi.se>p) {
				ll l=pl->fi.fi,r=pl->fi.se,id=pl->se;
				sg.erase(pl);
				sg[{l,p}]=id;
				sg[{p,r}]=id;
			}
		};
		split(l); split(r);
		auto pl=sg.lower_bound({l,L_});
		while (1) {
			auto pr=pl; ++pr;
			if (pl->fi.fi>=r) break;
			delseg(pl->fi.fi,pl->fi.se,pl->se);
			sg.erase(pl);
			pl=pr;
		}
		addseg(l,r,id);
		sg[{l,r}]=id;
	}
}s;

ll n;
int q;
ll d,ans;
int main() {
	scanf("%lld%d",&n,&q);
	s.init(1,n+1);
	rep(i,0,q) {
		ll l,r;
		scanf("%lld%lld%lld",&d,&l,&r);
		ans=0;
		++r;
		s.add(l,r,d,
			[&](ll l,ll r,ll v) {
				l%=mod; r%=mod;
				ans=(ans+1ll*(l+r-1)*(r-l)/2%mod*((d-v)%mod))%mod;
			},
			[&](ll l,ll r,ll v) { }
		);
		if (ans<0) ans+=mod;
		printf("%lld\n",ans);
	}
}
