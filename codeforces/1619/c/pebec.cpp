#include <bits/stdc++.h>
using namespace std;

#define ll                   long long
#define lld                  long double
#define pb                   push_back
#define mp                   make_pair
#define lb                   lower_bound
#define ub                   upper_bound
#define F                    first
#define S                    second
#define cel(x,a)             (((x) + (a) - 1) / (a))
#define all(v)               v.begin(), v.end()

const int N = 1e5 + 4;
const int M = 1e9 + 7;



void solve() {

    string a, s;
    cin >> a >> s;


    reverse(all(a));
    reverse(all(s));


    string b;
    int pos = 0;
    for (int i = 0; i < a.size(); i++) {

        if (pos >= s.size()) {
            cout << "-1\n";
            return;
        }
        if (s[pos] >= a[i]) {

            b += '0' + (s[pos] - a[i]);
            pos++;
        }
        else {
            if (pos + 1 >= s.size()) {
                cout << "-1\n";
                return;
            }

            if (s[pos + 1] != '1') {
                cout << "-1\n";
                return;
            }

            b += (10 + s[pos] - a[i]) + '0';
            pos += 2;
        }
    }

    while (pos < s.size()) {

        b += s[pos];
        pos++;
    }

    while(b.size() > 1 && b.back() == '0')
        b.pop_back();


    reverse(all(b));


    cout << b << "\n";

}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);


    int t;
    cin >> t;

    while (t--)
        solve();


    return 0;
}
