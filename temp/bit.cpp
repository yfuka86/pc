// ----------------------------------------------------------------------
template<typename T>
struct BIT {
  int n; vector<T> bit;
  BIT(int _n = 0) : n(_n), bit(n + 1) {}
  // sum of [0, i), 0 <= i <= n
  T sum(int i) { T s = 0; while (i > 0) { s += bit[i]; i -= i & -i; } return s;}
  // 0 <= i < n
  void add(int i, T x) { ++i; while (i <= n) { bit[i] += x; i += i & -i; } }
  //[l, r) 0 <= l < r < n
  T sum(int l, int r) { return sum(r) - sum(l); }
  // smallest i, sum(i) >= w, none -> n
  int lower_bound(T w) {
    if (w <= 0) return 0; int x = 0, l = 1; while (l * 2 <= n) l <<= 1;
    for (int k = l; k > 0; k /= 2) if (x + k <= n && bit[x + k] < w) { w -= bit[x + k]; x += k; }
    return x; }
};
// ----------------------------------------------------------------------

template<typename T>
struct BIT {
  int n;
  vector<T> bit;

  BIT(int _n = 0) : n(_n), bit(n + 1) {}

  // sum of [0, i), 0 <= i <= n
  T sum(int i) {
    T s = 0;
    while (i > 0) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }

  // 0 <= i < n
  void add(int i, T x) {
    ++i;
    while (i <= n) {
      bit[i] += x;
      i += i & -i;
    }
  }

  //[l, r) 0 <= l < r < n
  T sum(int l, int r) { return sum(r) - sum(l); }

  // smallest i, sum(i) >= w, none -> n
  int lower_bound(T w) {
    if (w <= 0) return 0;
    int x = 0, l = 1;
    while (l * 2 <= n) l <<= 1;

    for (int k = l; k > 0; k /= 2) {
      if (x + k <= n && bit[x + k] < w) {
        w -= bit[x + k];
        x += k;
      }
    }
    return x;
  }
};


template<class t>
struct BIT{
	vector<t> buf;
	int s;
	BIT(int n=0){init(n);}
	void init(int n){buf.clear();buf.resize(s=n,0);}
	void init(const vector<t>&a){
		s=si(a);
		buf.resize(s);
		rep(i,s)buf[i]=a[i];
		rep(i,s){
			int j=i+((i+1)&(-i-1));
			if(j<s)buf[j]+=buf[i];
		}
	}
	void add(int i,t v){
		for(;i<s;i+=(i+1)&(-i-1))
			buf[i]+=v;
	}
	t get(int i){
		t res=0;
		for(;i>=0;i-=(i+1)&(-i-1))
			res+=buf[i];
		return res;
	}
	t sum(int b,int e){
		return get(e-1)-get(b-1);
	}
	void add_range(int b,int e,t v){
		add(b,v);
		add(e,-v);
	}
	int kth(int k){
		int res=0;
		for(int i=topbit(s);i>=0;i--){
			int w=res+(1<<i);
			if(w<=s&&buf[w-1]<=k){
				k-=buf[w-1];
				res=w;
			}
		}
		return res;
	}
	//yukicoder No.1024
	int kth_helper(int k,int i){
		return kth(k+get(i-1));
	}
};
