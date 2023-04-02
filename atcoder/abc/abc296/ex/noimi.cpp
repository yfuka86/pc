#line 1 "Main.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <atcoder/modint>
#line 4 "nachia\\set\\dsu.hpp"

namespace nachia {

struct Dsu{
private:
    int N;
    std::vector<int> P;
    std::vector<int> H;
public:
    Dsu() : N(0) {}
    Dsu(int n) : N(n), P(n, -1), H(n) {
        for(int i=0; i<n; i++) H[i] = i;
    }
    int leader(int u){
        if(P[u] < 0) return u;
        int v = P[u];
        while(P[v] >= 0){ P[u] = P[v]; u = v; v = P[v]; }
        return P[u];
    }
    int append(){
        int n = P.size();
        P.push_back(-1);
        H.push_back(n);
        return n;
    }
    int label(int u){ return H[leader(u)]; }
    int operator[](int u){ return H[leader(u)]; }
    void merge(int u, int v, int newLabel){
        if(newLabel < 0) newLabel = u;
        u = leader(u);
        v = leader(v);
        if(u == v){ H[u] = newLabel; return; }
        N--;
        if(-P[u] < -P[v]) std::swap(u, v);
        P[u] += P[v];
        H[P[v] = u] = newLabel;
    }
    int merge(int u, int v){ merge(u, v, u); return u; }
    int count(){ return N; }
    int size(int u){ return -P[leader(u)]; }
    bool same(int u, int v){ return leader(u) == leader(v); }
};

} // namespace nachia
#line 7 "Main.cpp"
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
const i64 INF = 1001001001001001001;

using Modint = atcoder::static_modint<998244353>;

struct Node {
    int fracNum;
    int mass;
    vector<int> stat;
    vector<int> moveto;
};

vector<Node> frac;

void searchFrac(int n, vector<int> s, int fnum){
    if(n == 0){
        Node node;
        node.fracNum = fnum;
        node.mass = 0; for(int a : s) if(a != -1) node.mass++;
        node.stat = std::move(s);
        frac.push_back(std::move(node));
        return;
    }
    if(!s.empty() && s.back() != -1){
        s.push_back(s.back());
        searchFrac(n-1, s, fnum);
        s.back() = -1;
        searchFrac(n-1, s, fnum);
    }
    else{
        s.push_back(-1);
        searchFrac(n-1, s, fnum);
        rep(t,fnum){
            s.back() = t;
            searchFrac(n-1, s, fnum);
        }
        s.back() = fnum;
        searchFrac(n-1, s, fnum+1);
    }
}

int main(){
    int N; cin >> N;
    int M; cin >> M;
    searchFrac(M, {}, 0);

    int fracKind = frac.size();
    rep(i,fracKind) rep(j,fracKind){
        auto& a = frac[i];
        auto& b = frac[j];
        nachia::Dsu dsu(M*2);
        rep(m1,M) rep(m2,m1) if(a.stat[m1] != -1 && a.stat[m1] == a.stat[m2]) dsu.merge(m1, m2);
        rep(m,M) if(a.stat[m] != -1 && b.stat[m] != -1) dsu.merge(m, M + m);
        bool ok = true;
        rep(m1,M-1) if(b.stat[m1] != -1 && b.stat[m1+1] != -1) dsu.merge(M+m1, M+m1+1);
        rep(m1,M) rep(m2,m1) if(b.stat[m1] != -1 && b.stat[m1] == b.stat[m2]) if(!dsu.same(M+m1, M+m2)) ok = false;
        rep(m1,M) rep(m2,m1) if(b.stat[m1] != -1 && b.stat[m2] != -1 && b.stat[m1] != b.stat[m2]) if(dsu.same(M+m1, M+m2)) ok = false;
        if(dsu.count() != M*2 - a.mass - b.mass + b.fracNum) ok = false;
        if(ok) a.moveto.push_back(j);
    }

    int sinf = 1001001001;
    vector<int> dp(fracKind, sinf);
    vector<string> S(N);
    rep(n,N) cin >> S[n];
    rep(t,2){
        while(S.back() == string(M, '.')){ S.pop_back(); N--; }
        reverse(S.begin(), S.end());
    }
    int ansoff = 0;
    rep(i,N) rep(j,M) if(S[i][j] == '#') ansoff++;
    dp[0] = -ansoff;
    rep(n,N){
        string s = S[n];
        vector<int> tmp(fracKind, sinf);
        rep(i,fracKind) for(int j : frac[i].moveto) tmp[j] = min(tmp[j], dp[i] + frac[j].mass);
        rep(i,fracKind){
            bool ok = true;
            rep(j,M) if(s[j] == '#' && frac[i].stat[j] == -1) ok = false;
            if(!ok) tmp[i] = sinf;
        }
        swap(dp, tmp);
    }
    rep(i,fracKind) if(frac[i].fracNum != 1) dp[i] = sinf;
    cout << *min_element(dp.begin(), dp.end()) << endl;
    return 0;
}



struct ios_do_not_sync{
    ios_do_not_sync(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} ios_do_not_sync_instance;

