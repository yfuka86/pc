#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BIT2D {
    int H, W;
    vector<vector<T>> bit;  // データの格納先
    BIT2D(int H_, int W_) { init(H_, W_); }
    void init(int H_, int W_) {
        H = H_ + 1;
        W = W_ + 1;
        bit.assign(H, vector<T>(W, 0));
    }
    void add(int h, int w, T x) {
        for (int i = h; i < H; i += (i & -i)) {
            for (int j = w; j < W; j += (j & -j)) {
                bit[i][j] += x;
            }
        }
    }
    // 1≦i≦h かつ 1≦j≦w
    T sum(int h, int w) {
        T s(0);
        for (int i = h; i > 0; i -= (i & -i)) {
            for (int j = w; j > 0; j -= (j & -j)) {
                s += bit[i][j];
            }
        }
        return s;
    }
    // h1≦i<h2 かつ w1≦j<w2
    T query(int h1, int w1, int h2, int w2) {
        return sum(h2 - 1, w2 - 1) - sum(h2 - 1, w1 - 1) - sum(h1 - 1, w2 - 1) + sum(h1 - 1, w1 - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    cin >> N >> M;
    vector<string>S(N);
    vector<array<int,4>>query;
    for(int i = 0; i < N; i++) {
        cin >> S[i];
        for(int j = 0; j < N; j++) {
            if(S[i][j] == 'O') {
                query.push_back({2*M+2*(i+1)+(j+1),-1,i+1,j+1});
            }
        }
    }
    int Q;
    cin >> Q;
    vector<int>ans(Q);
    for(int i = 0; i < Q; i++) {
        int X,Y;
        cin >> X >> Y;
        query.push_back({2*X+Y,i,X,Y});
    }
    sort(query.rbegin(),query.rend());
    BIT2D<int> bit(N,N);
    for(int i = 0; i < query.size(); i++) {
        if(query[i][1] == -1) {
            bit.add(query[i][2],query[i][3],1);
        }
        else {
            ans[query[i][1]] = bit.sum(query[i][2],query[i][3]);
        }
    }
    for(int i = 0; i < Q; i++) {
        cout << ans[i] << '\n';
    }
}
