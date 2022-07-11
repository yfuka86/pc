#include "bits/stdC++.h"
using namespace std;
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i;
		cin>>n>>m;
		vector<ll> a(n+1);
		vector<int> deg(m,2),b(n+1),id(n+1);
		vector<pair<int,int>> p(m);
		vector<vector<int>> e(n+1);
		iota(all(id),0);
		set<int> s(all(id));
		for (i=1;i<=n;i++) cin>>a[i];
		for (i=1;i<=n;i++) cin>>b[i];
		for (i=0;i<m;i++)
		{
			auto &[l,r]=p[i];
			cin>>l>>r;
			e[l-1].push_back(i);
			e[r].push_back(i);
		}
		for (i=1;i<=n;i++) a[i]-=b[i];
		for (i=1;i<=n;i++) a[i]+=a[i-1];
		queue<int> q;
		for (i=0;i<=n;i++) if (!a[i]) q.push(i),s.erase(i);
		while (q.size())
		{
			int x=q.front();q.pop();
			for (int y:e[x]) if (!--deg[y])
			{
				auto [l,r]=p[y];
				auto lt=s.lower_bound(l),rt=s.upper_bound(r);
				for (auto it=lt;it!=rt;++it) q.push(*it);
				s.erase(lt,rt);
			}
		}
		cout<<(s.size()?"NO\n":"YES\n");
	}
}
