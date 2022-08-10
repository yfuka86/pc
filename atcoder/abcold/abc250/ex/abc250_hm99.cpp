#include <stdio.h>
#include <atcoder/dsu>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000
vector<vector<pair<long long,int>>> dis;
priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>, greater<pair<long long,pair<int,int>>>> Q;

void get(vector<vector<int>> &E,vector<int> &u,vector<int> &v,vector<int> &c,vector<int> &leader){
	leader.push_back(-1);
	int N,M,K,L;
	N = E.size();
	M = u.size();


	dis.assign(N,vector<pair<long long,int>>(2,make_pair(Inf,leader.size()-1)));
		rep(i,leader.size()){
		if(leader[i]!=-1){
			dis[i][0] = make_pair(0,i);
			Q.emplace(0, make_pair(i,i));
		}
	}

	while(Q.size()>0){
		long long D = Q.top().first;
		int uu = Q.top().second.first;
		int l = Q.top().second.second;
		Q.pop();
		if(dis[uu][0].first!=D&&dis[uu][1].first!=D)continue;

		rep(i,E[uu].size()){
			int ind = E[uu][i];
			int vv = u[ind] ^ v[ind] ^ uu;
			long long DD = D + c[ind];

			rep(j,2){
				if(dis[vv][j].first > DD){
					if(leader[dis[vv][j].second] == leader[l]){
						dis[vv][j].first = DD;
						dis[vv][j].second = l;
						Q.emplace(DD,make_pair(vv,l));
						break;
					}
					else{
						dis[vv].insert(dis[vv].begin()+j,make_pair(DD,l));
						Q.emplace(DD,make_pair(vv,l));
						dis[vv].pop_back();
						break;
					}
				}
				else if(leader[dis[vv][j].second]==leader[l])break;
			}

		}

	}
}

int main(){

	int N,M,K;
	cin>>N>>M>>K;

	vector<vector<int>> E(N);
	vector<int> u(M),v(M),c(M);
	rep(i,M){
		scanf("%d %d %d",&u[i],&v[i],&c[i]);
		u[i]--,v[i]--;
		E[u[i]].push_back(i);
		E[v[i]].push_back(i);
	}

	vector<pair<long long,pair<int,int>>> pq;
	auto start = chrono::system_clock::now();
	dsu D(K);
	vector<pair<long long,pair<int,int>>> temp;
	vector<int> leader(K);
	while(D.size(0)!=K){

		rep(i,K)leader[i] = D.leader(i);
		get(E,u,v,c,leader);
		temp.assign(K,make_pair(Inf,make_pair(0,0)));
		rep(i,K){
			auto x = dis[i][0];
			if(leader[x.second]==leader[i])x = dis[i][1];
			temp[leader[i]] = min(temp[leader[i]],make_pair(x.first,make_pair(i,x.second)));
		}

		rep(i,temp.size()){
			if(temp[i].first==Inf)continue;
			int uu = temp[i].second.first,vv = temp[i].second.second;
			if(D.same(uu,vv))continue;
			D.merge(uu,vv);
			pq.push_back(temp[i]);
		}
		//cout<<chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count()<<endl;
	}

	int QQ;
	cin>>QQ;
	vector<long long> t(QQ);
	vector<int> x(QQ),y(QQ);
	rep(i,QQ){
		scanf("%d %d %lld",&x[i],&y[i],&t[i]);
		x[i]--,y[i]--;
	}


	{
		sort(pq.rbegin(),pq.rend());
		D = dsu(K);
		rep(i,QQ){
			while(pq.size()>0 && pq.back().first<=t[i]){
				D.merge(pq.back().second.first,pq.back().second.second);
				pq.pop_back();
			}
			if(D.same(x[i],y[i]))printf("Yes\n");
			else printf("No\n");
		}
	}


    return 0;
}
