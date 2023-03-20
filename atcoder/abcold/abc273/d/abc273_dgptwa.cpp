#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int H, W, N, rs, cs;
    cin >> H >> W >> rs >> cs >> N;

    vector<set<int>> walls_x(W + 1);
    vector<set<int>> walls_y(H + 1);
    for (int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c;
        walls_x[c].insert(r);
        walls_y[r].insert(c);
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        char di;
        int li;
        cin >> di >> li;

        int dr = 0, dc = 0;
        if (di == 'U') dr = -1;
        else if (di == 'R') dc = 1;
        else if (di == 'D') dr = 1;
        else dc = -1; // di == 'L'

        if (dr != 0) {
            auto it = dr == -1 ? walls_x[cs].lower_bound(rs) : walls_x[cs].upper_bound(rs);
            if (it != walls_x[cs].end() && dr * (*it - rs) <= dr * li) {
                li = dr * (*it - rs) - dr;
            }
            rs += dr * li;
        } else {
            auto it = dc == -1 ? walls_y[rs].lower_bound(cs) : walls_y[rs].upper_bound(cs);
            if (it != walls_y[rs].end() && dc * (*it - cs) <= dc * li) {
                li = dc * (*it - cs) - dc;
            }
            cs += dc * li;
        }

        rs = max(1, min(rs, H));
        cs = max(1, min(cs, W));

        cout << rs << " " << cs << endl;
    }

    return 0;
}
