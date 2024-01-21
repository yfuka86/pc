#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(obj) (obj).begin(),(obj).end()
#define SPEED cin.tie(0);ios::sync_with_stdio(false);
template<class T> using PQ = priority_queue<T>;
template<class T> using PQR = priority_queue<T,vector<T>,greater<T>>;

constexpr long long MOD = (long long)1e9 + 7;
constexpr long long MOD2 = 998244353;
constexpr long long HIGHINF = (long long)1e18;
constexpr long long LOWINF = (long long)1e15;
constexpr long double PI = 3.1415926535897932384626433L;

template <class T> vector<T> multivector(size_t N,T init){return vector<T>(N,init);}
template <class... T> auto multivector(size_t N,T... t){return vector<decltype(multivector(t...))>(N,multivector(t...));}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}
template <class T> void chmax(T& a, const T b){a=max(a,b);}
template <class T> void chmin(T& a, const T b){a=min(a,b);}
void YN(bool flg) {cout << (flg ? "YES" : "NO") << endl;}
void Yn(bool flg) {cout << (flg ? "Yes" : "No") << endl;}
void yn(bool flg) {cout << (flg ? "yes" : "no") << endl;}


template<class Operator> class Tree {
	Operator Op;
	using typeDist = decltype(Op.unitDist);
	size_t num;
	size_t ord;
public:
	vector<vector<pair<size_t,typeDist>>> edge;
	vector<size_t> depth;
	vector<size_t> order;
	vector<size_t> reorder;
	vector<typeDist> dist;
	vector<pair<size_t,typeDist>> parent;
	vector<vector<pair<size_t,typeDist>>> child;
	vector<array<pair<size_t,typeDist>,Operator::bit>> ancestor;
	vector<size_t> size;
	vector<vector<size_t>> descendant;
	vector<size_t> head;
	vector<size_t> hldorder;
    vector<size_t> eulertour;
    vector<pair<size_t,size_t>> eulertourrange;
	Tree(const int num):num(num),edge(num),depth(num,-1),order(num),dist(num){}
	//O(1) anytime
	void makeEdge(const int& from, const int& to, const typeDist w = 1) {
		edge[from].push_back({to,w});
	}
	//O(N) anytime
	void makeDepth(const int root) {
		depth[root] = 0;
		dist[root] = Op.unitDist;
		ord = 0;
		dfs1(root);
		order[ord++] = root;
		reverse_copy(order.begin(),order.end(),back_inserter(reorder));
	}
	//O(N) anytime
	void makeDepth(void) {
		ord = 0;
		for(size_t root = 0; root < num; ++root) {
			if(depth[root] != -1) continue;
			depth[root] = 0;
			dist[root] = Op.unitDist;
			dfs1(root);
			order[ord++] = root;
		}
		reverse_copy(order.begin(),order.end(),back_inserter(reorder));
	}
	//for makeDepth
	void dfs1(int curr, int prev = -1){
		for(auto& e:edge[curr]){
			int next = e.first;
			if(next==prev) continue;
			depth[next] = depth[curr] + 1;
			dist[next]  = Op.funcDist(dist[curr],e.second);
			dfs1(next,curr);
			order[ord++] = next;
		}
	}
	//O(N) after makeDepth
	void makeParent(void) {
		parent.resize(num,make_pair(num,Op.unitDist));
		for (size_t i = 0; i < num; ++i) for (auto& e : edge[i]) if (depth[i] > depth[e.first]) parent[i] = e;
	}
	//O(N) after makeDepth
	void makeChild(void) {
		child.resize(num);
		for (size_t i = 0; i < num; ++i) for (auto& e : edge[i]) if (depth[i] < depth[e.first]) child[i].push_back(e);
	}
	//O(NlogN) after makeDepth and makeParent
	void makeAncestor(void) {
		ancestor.resize(num);
		for (size_t i = 0; i < num; ++i) ancestor[i][0] = (parent[i].first!=num?parent[i]:make_pair(i,Op.unitLca));
		for (size_t j = 1; j < Operator::bit; ++j) {
			for (size_t i = 0; i < num; ++i) {
				size_t k = ancestor[i][j - 1].first;
				ancestor[i][j] = Op.funcLca(ancestor[k][j - 1],ancestor[i][j - 1]);
			}
		}
	}
	//O(logN) after makeAncestor
	//return {lca,lca_dist} l and r must be connected
	pair<size_t,typeDist> lca(size_t l, size_t r) {
		if (depth[l] < depth[r]) swap(l, r);
		int diff = depth[l] - depth[r];
		auto ancl = make_pair(l,Op.unitLca);
		auto ancr = make_pair(r,Op.unitLca);
		for (int j = 0; j < Operator::bit; ++j) {
			if (diff & (1 << j)) {
				ancl = Op.funcLca(ancestor[ancl.first][j],ancl);
			}
		}
		if(ancl.first==ancr.first) return ancl;
		for (int j = Operator::bit - 1; 0 <= j; --j) {
			if(ancestor[ancl.first][j].first!=ancestor[ancr.first][j].first) {
				ancl = Op.funcLca(ancestor[ancl.first][j],ancl);
				ancr = Op.funcLca(ancestor[ancr.first][j],ancr);
			}
		}
		ancl = Op.funcLca(ancestor[ancl.first][0],ancl);
		ancr = Op.funcLca(ancestor[ancr.first][0],ancr);
		return Op.funcLca(ancl,ancr);
	}
	//O(N) anytime
	int diameter(void){
		makeDepth(0);
		int tmp = max_element(depth.begin(), depth.end()) - depth.begin();
		makeDepth(tmp);
		return *max_element(depth.begin(), depth.end());
	}
	//O(N^2) after makeDepth (include self)
	void makeDescendant(void) {
		descendant.resize(num);
		for (size_t i = 0; i < num; ++i) descendant[i].push_back(i);
		for (size_t i = 0; i < num; ++i) for (auto& e : edge[order[i]]) if (depth[order[i]] < depth[e.first]) for(auto k: descendant[e.first]) descendant[order[i]].push_back(k);
	}
	//O(N) after makeChild
	void makeSize(void) {
		size.resize(num,1);
		for (size_t i:order) for (auto e : child[i]) size[i] += size[e.first];
	}
	//(N) after makeDepth and makeChild
	template<class typeReroot> vector<typeReroot> rerooting(vector<typeReroot> rerootdp,vector<typeReroot> rerootparent) {
		for(size_t pa:order) for(auto& e:child[pa]) rerootdp[pa] = Op.funcReroot(rerootdp[pa],rerootdp[e.first]);
		for(size_t pa:reorder) {
			if(depth[pa]) rerootdp[pa] = Op.funcReroot(rerootdp[pa],rerootparent[pa]);
			size_t m = child[pa].size();
			for(int j = 0; j < m && depth[pa]; ++j){
				size_t ch = child[pa][j].first;
				rerootparent[ch] = Op.funcReroot(rerootparent[ch],rerootparent[pa]);
			}
			if(m <= 1) continue;
			vector<typeReroot> l(m),r(m);
			for(int j = 0; j < m; ++j) {
				size_t ch = child[pa][j].first;
				l[j] = rerootdp[ch];
				r[j] = rerootdp[ch];
			}
			for(int j = 1; j+1 < m; ++j) l[j] = Op.funcRerootMerge(l[j],l[j-1]);
			for(int j = m-2; 0 <=j; --j) r[j] = Op.funcRerootMerge(r[j],r[j+1]);
			size_t chl = child[pa].front().first;
			size_t chr = child[pa].back().first;
			rerootparent[chl] = Op.funcReroot(rerootparent[chl],r[1]);
			rerootparent[chr] = Op.funcReroot(rerootparent[chr],l[m-2]);
			for(int j = 1; j+1 < m; ++j) {
				size_t ch = child[pa][j].first;
				rerootparent[ch] = Op.funcReroot(rerootparent[ch],l[j-1]);
				rerootparent[ch] = Op.funcReroot(rerootparent[ch],r[j+1]);
			}
		}
		return rerootdp;
    }
	//O(N) after makeDepth,makeParent,makeChild
	void heavyLightDecomposition(){
		head.resize(num);
		hldorder.resize(num);
		iota(head.begin(),head.end(),0);
		for(size_t& pa:reorder) {
			pair<size_t,size_t> maxi = {0,num};
			for(auto& e:child[pa]) maxi = max(maxi,{size[e.first],e.first});
			if(maxi.first) head[maxi.second] = head[pa];
		}
		stack<size_t> st_head,st_sub;
		size_t cnt = 0;
		for(size_t& root:reorder){
			if(depth[root]) continue;
			st_head.push(root);
			while(st_head.size()){
				size_t h = st_head.top();
				st_head.pop();
				st_sub.push(h);
				while (st_sub.size()){
					size_t pa = st_sub.top();
					st_sub.pop();
					hldorder[pa] = cnt++;
					for(auto& e:child[pa]) {
						if(head[e.first]==head[pa]) st_sub.push(e.first);
						else st_head.push(e.first);
					}
				}
			}
		}
	}
	//after hld type 0: vertex, 1: edge
	vector<pair<size_t,size_t>> path(size_t u,size_t v,int type = 0) {
		vector<pair<size_t,size_t>> path;
		while(1){
			if(hldorder[u]>hldorder[v]) swap(u,v);
			if(head[u]!=head[v]) {
				path.push_back({hldorder[head[v]],hldorder[v]});
				v=parent[head[v]].first;
			}
			else {
				path.push_back({hldorder[u],hldorder[v]});
				break;
			}
		}
        reverse(path.begin(),path.end());
        if(type) path.front().first++;
		return path;
	}
	size_t hldLca(size_t u,size_t v){
		while(1){
			if(hldorder[u]>hldorder[v]) swap(u,v);
			if(head[u]==head[v]) return u;
			v=parent[head[v]].first;
		}
	}
    //O(N) after makeChild and makeParent
	void makeEulerTour(void){
        dfs2(reorder.front());
        eulertourrange.resize(num);
        for(int i = 0; i < eulertour.size(); ++i) eulertourrange[eulertour[i]].second = i;
        for(int i = eulertour.size()-1; 0 <= i; --i) eulertourrange[eulertour[i]].first = i;
		return;
	}
    //for makeEulerTour
	void dfs2(int from, int prev = -1){
		eulertour.push_back(from);
        for(auto& e:child[from]){
            int to = e.first;
            dfs2(to,from);
    		eulertour.push_back(from);
        }
	}
};
//depth,dist
//https://atcoder.jp/contests/abc126/tasks/abc126_d
//child
//https://atcoder.jp/contests/abc133/tasks/abc133_e
//lca
//https://atcoder.jp/contests/abc014/tasks/abc014_4
//weighted lca
//https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h
//https://atcoder.jp/contests/cf16-tournament-round1-open/tasks/asaporo_c
//diameter
//https://atcoder.jp/contests/agc033/tasks/agc033_c
//descendant
//https://atcoder.jp/contests/code-thanks-festival-2018/tasks/code_thanks_festival_2018_f
//rerooting
//https://yukicoder.me/problems/no/922
//size
//https://yukicoder.me/problems/no/872
//eulerTour
//https://yukicoder.me/problems/no/900
//hld
//https://yukicoder.me/problems/no/399
//https://yukicoder.me/problems/no/650
template<class typeDist> struct treeOperator{
	static const size_t bit = 20;
	typeDist unitDist = 0;
	typeDist unitLca = 0;
	typeDist funcDist(const typeDist& parent,const typeDist& w){return parent+w;}
	pair<size_t,typeDist> funcLca(const pair<size_t,typeDist>& l,const pair<size_t,typeDist>& r){return make_pair(l.first,l.second+r.second);}
	template<class typeReroot> typeReroot funcReroot(const typeReroot& l,const typeReroot& r) {
		return {l.first+r.first+r.second,l.second+r.second};
	}
	template<class typeReroot> typeReroot funcRerootMerge(const typeReroot& l,const typeReroot& r) {
		return {l.first+r.first,l.second+r.second};
	}
};
//Tree<treeOperator<ll>> tree(N);

template<class Operator> class LazySegmentTree {
    Operator Op;
	using typeNode = decltype(Op.unitNode);
	using typeLazy = decltype(Op.unitLazy);
	size_t num;
	size_t length;
	size_t height;
	vector<typeNode> node;
	vector<typeLazy> lazy;
	vector<pair<size_t,size_t>> range;
public:

	//unitで初期化
	LazySegmentTree(const size_t num) : num(num) {
		for (length = 1,height = 0; length < num; length *= 2, height++);
		node.resize(2 * length, Op.unitNode);
		lazy.resize(2 * length, Op.unitLazy);
		for (int i = 0; i < num; ++i) node[i + length] = Op.unitNode;
		for (int i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		range.resize(2 * length);
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
	}

	// //同じinitで初期化
	LazySegmentTree(const size_t num, const typeNode init) : num(num) {
		for (length = 1,height = 0; length < num; length *= 2, height++);
		node.resize(2 * length, Op.unitNode);
		lazy.resize(2 * length, Op.unitLazy);
		for (int i = 0; i < num; ++i) node[i + length] = init;
		for (int i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		range.resize(2 * length);
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
	}

	//vectorで初期化
	LazySegmentTree(const vector<typeNode>& vec) : num(vec.size()) {
		for (length = 1,height = 0; length < vec.size(); length *= 2, height++);
		node.resize(2 * length, Op.unitNode);
		lazy.resize(2 * length, Op.unitLazy);
		for (int i = 0; i < vec.size(); ++i) node[i + length] = vec[i];
		for (int i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		range.resize(2 * length);
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
	}

	void propagate(int k) {
		if(lazy[k] == Op.unitLazy) return;
		node[k] = Op.funcMerge(node[k],lazy[k],range[k].second-range[k].first);
		if(k < length) lazy[2*k+0] = Op.funcLazy(lazy[2*k+0],lazy[k]);
		if(k < length) lazy[2*k+1] = Op.funcLazy(lazy[2*k+1],lazy[k]);
		lazy[k] = Op.unitLazy;
    }


	//update [a,b)
    void update(int a, int b, typeLazy x) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) lazy[l] = Op.funcLazy(lazy[l],x), propagate(l),l++;
			if(r&1) --r,lazy[r] = Op.funcLazy(lazy[r],x), propagate(r);
		}
		l = a + length, r = b + length - 1;
		while ((l>>=1),(r>>=1),l) {
			if(lazy[l] == Op.unitLazy) node[l] = Op.funcNode(Op.funcMerge(node[(l<<1)+0],lazy[(l<<1)+0],range[(l<<1)+0].second-range[(l<<1)+0].first),Op.funcMerge(node[(l<<1)+1],lazy[(l<<1)+1],range[(l<<1)+1].second-range[(l<<1)+1].first));
			if(lazy[r] == Op.unitLazy) node[r] = Op.funcNode(Op.funcMerge(node[(r<<1)+0],lazy[(r<<1)+0],range[(r<<1)+0].second-range[(r<<1)+0].first),Op.funcMerge(node[(r<<1)+1],lazy[(r<<1)+1],range[(r<<1)+1].second-range[(r<<1)+1].first));
		}
    }

	//get [a,b)
	typeNode get(int a, int b) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		typeNode vl = Op.unitNode, vr = Op.unitNode;
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) vl = Op.funcNode(vl,Op.funcMerge(node[l],lazy[l],range[l].second-range[l].first)),l++;
			if(r&1) r--,vr = Op.funcNode(Op.funcMerge(node[r],lazy[r],range[r].second-range[r].first),vr);
		}
		return Op.funcNode(vl,vr);
	}

	//return [0,length]
	int PrefixBinarySearch(typeNode var) {
		int l = length, r = 2*length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		if(!Op.funcCheck(node[1],var)) return num;
		typeNode ret = Op.unitNode;
		size_t idx = 2;
		for(; idx < 2*length; idx<<=1){
			if(!Op.funcCheck(Op.funcNode(ret,Op.funcMerge(node[idx],lazy[idx],range[idx].second-range[idx].first)),var)) {
				ret = Op.funcNode(ret,Op.funcMerge(node[idx],lazy[idx],range[idx].second-range[idx].first));
				idx++;
			}
		}
		return min((idx>>1) - length,num);
	}

	//range[l,r) return [l,r]
	int BinarySearch(size_t l, size_t r, typeNode var) {
		if (l < 0 || length <= l || r < 0 || length < r) return -1;
		for (int i = height; 0 < i; --i) propagate((l+length) >> i), propagate((r+length-1) >> i);
		typeNode ret = Op.unitNode;
		size_t off = l;
		for(size_t idx = l+length; idx < 2*length && off < r; ){
			if(range[idx].second<=r && !Op.funcCheck(Op.funcNode(ret,Op.funcMerge(node[idx],lazy[idx],range[idx].second-range[idx].first)),var)) {
				ret = Op.funcNode(ret,Op.funcMerge(node[idx],lazy[idx],range[idx].second-range[idx].first));
				off = range[idx++].second;
				if(!(idx&1)) idx >>= 1;
			}
			else{
				idx <<=1;
			}
		}
		return off;
	}

	void print(){
		// cout << "node" << endl;
		// for(int i = 1,j = 1; i < 2*length; ++i) {
		// 	cout << node[i] << " ";
		// 	if(i==((1<<j)-1) && ++j) cout << endl;
		// }
		// cout << "lazy" << endl;
		// for(int i = 1,j = 1; i < 2*length; ++i) {
		// 	cout << lazy[i] << " ";
		// 	if(i==((1<<j)-1) && ++j) cout << endl;
		// }
		cout << "vector" << endl;
		cout << "{ " << get(0,1);
		for(int i = 1; i < length; ++i) cout << ", " << get(i,i+1);
		cout << " }" << endl;
	}
};

//node:総和　lazy:加算
template<class typeNode, class typeLazy> struct nodeSumLazyAdd {
	typeNode unitNode = 0;
	typeLazy unitLazy = 0;
	typeNode funcNode(typeNode l,typeNode r){return l+r;}
	typeLazy funcLazy(typeLazy l,typeLazy r){return l+r;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return l+r*len;}
	bool funcCheck(typeNode nodeVal,typeNode var){return var <= nodeVal;}
    // LazySegmentTree<nodeSumLazyPlus<ll,ll>> Seg(N,0);
};

//node:最小　lazy:加算
template<class typeNode, class typeLazy> struct nodeMinLazyAdd {
	typeNode unitNode = 1234567890;
	typeLazy unitLazy = 0;
	typeNode funcNode(typeNode l,typeNode r){return min(l,r);}
	typeLazy funcLazy(typeLazy l,typeLazy r){return l+r;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return l+r;}
    // LazySegmentTree<nodeMinLazyAdd<ll,ll>> Seg(N,0);
	//verify https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H
};

//node:mod和　lazy:mod加算
template<class typeNode, class typeLazy> struct nodeModSumLazyModAdd {
	typeNode unitNode = 0;
	typeLazy unitLazy = 0;
	typeNode funcNode(typeNode l,typeNode r){return (l+r)%MOD;}
	typeLazy funcLazy(typeLazy l,typeLazy r){return (l+r)%MOD;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return (l+(r*len)%MOD)%MOD;}
	// LazySegmentTree<nodeModSumLazyModAdd<ll,ll>> dp(N+3,0);
    //verify https://atcoder.jp/contests/code-festival-2018-quala/tasks/code_festival_2018_quala_d
};

//node:最大　lazy:更新
template<class typeNode, class typeLazy> struct nodeMaxLazyUpdate {
	typeNode unitNode = 0;
	typeLazy unitLazy = 0;
	typeNode funcNode(typeNode l,typeNode r){return max(l,r);}
	typeLazy funcLazy(typeLazy l,typeLazy r){return r;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return r!=0?r*len:l;}
    // LazySegmentTree<nodeMaxLazyUpdate<ll,ll>> Seg(N+2,0);
    //verify https://atcoder.jp/contests/nikkei2019-final/tasks/nikkei2019_final_d
};

//node:最小　lazy:更新
template<class typeNode, class typeLazy> struct nodeMinLazyUpdate {
	typeNode unitNode = 12345678910;
	typeLazy unitLazy = 0;
	typeNode funcNode(typeNode l,typeNode r){return min(l,r);}
	typeLazy funcLazy(typeLazy l,typeLazy r){return r;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return r!=0?r*len:l;}
	//LazySegmentTree<ll,ll,nodeMinLazyUpdate<ll,ll>> Seg(N,HIGHINF,0);
    //verify https://atcoder.jp/contests/code-festival-2018-final/tasks/code_festival_2018_final_e
};

//node:GCD　lazy:更新
template<class typeNode, class typeLazy> struct nodeGCDLazyUpdate {
	typeNode unitNode = 0;
	typeLazy unitLazy = 0;
	typeNode funcNode(typeNode l,typeNode r){return ((r == 0) ? l : funcNode(r, l % r));}
	typeLazy funcLazy(typeLazy l,typeLazy r){return r;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return r!=0?r:l;}
    // LazySegmentTree<nodeGCDLazyUpdate<ll,ll>> Seg(A);
    //verify https://atcoder.jp/contests/abc125/tasks/abc125_c
};

//node:総和　lazy:更新
template<class typeNode, class typeLazy> struct nodeSumLazyUpdate {
	typeNode unitNode = 0;
	typeLazy unitLazy = -2000;
	typeNode funcNode(typeNode l,typeNode r){return l+r;}
	typeLazy funcLazy(typeLazy l,typeLazy r){return r;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return r!=-2000?r*len:l;}
	bool funcCheck(typeNode nodeVal,typeNode var){return var <= nodeVal;}
	// LazySegmentTree<nodeSumLazyUpdate<ll,ll>> Seg(N,0,-2000,0);
    //verify https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I
};

int main() {

    SPEED
    int N; cin >> N;
    Tree<treeOperator<ll>> tree(N);
    for(int i = 0; i < N-1; ++i) {
        int u,v; cin >> u >> v;
        u--,v--;
        tree.makeEdge(u,v);
        tree.makeEdge(v,u);
    }
    int root = 0;
    tree.makeDepth(root);
    tree.makeChild();
    tree.makeParent();
    tree.makeSize();
    tree.heavyLightDecomposition();
    LazySegmentTree<nodeSumLazyAdd<ll,ll>> seg(N,0),seg2(N,0);
    ll ans = 0;
    vector<ll> dp1(N),dp2(N),dp(N);
    for(int i = 0; i < N; ++i) {
        dp1[i] = seg.get(tree.hldorder[i],tree.hldorder[i]+1);
        auto path = tree.path(root,i);
        for(auto p:path){
            int l = p.first,r = p.second + 1;
            seg.update(l,r,1);
        }

        seg2.update(tree.hldorder[i],tree.hldorder[i]+1,1);
        for(auto e:tree.child[i]){
            int ch = e.first;
            dp2[ch] = seg2.get(tree.hldorder[ch],tree.hldorder[ch]+tree.size[ch]);
        }
    }
    dp[root] = accumulate(ALL(dp1),0LL);
    for(int pa:tree.reorder){
        for(auto e:tree.child[pa]){
            int ch = e.first;
            dp[ch] = dp[pa] - dp1[ch] + ch - dp2[ch];
        }
    }
    for(auto e:dp) cout << e << " ";
    return 0;
}
