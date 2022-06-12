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
