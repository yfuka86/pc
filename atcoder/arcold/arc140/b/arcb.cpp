#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define INTINF 1 << 30
#define LLINF (long long)1 << (long long)62

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<long long> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;
typedef vector<pair<int,int>> vpii;
typedef vector<string> vs;
typedef vector<vector<char>> vvc;

int main(){
    int N;
    string S;
    cin >> N >> S;
    multiset<int> depth;
    int ind = 0;
    int cntA = 0;
    int cntC = 0;
    bool flag = false;
    while(ind < (int)S.size()){
        if(S[ind] == 'A'){
            if(flag){
                int a = min(cntA, cntC);
                if(a) depth.insert(a);
                flag = false;
                cntA = 0;
                cntC = 0;
            }
            cntA++;
        }else if(S[ind] == 'R'){
            if(flag){
                int a = min(cntA, cntC);
                if(a) depth.insert(a);
                flag = false;
                cntA = 0;
                cntC = 0;
            }
            if(cntA) flag = true;
        }else{
            if(flag) cntC++;
        }
        ind++;
        if(ind == (int)S.size() && flag){
            int a = min(cntA, cntC);
            if(a) depth.insert(a);
            flag = false;
            cntA = 0;
            cntC = 0;
        }
    }
    bool ODD = true;
    int ans = 0;
    while(!depth.empty()){
        if(ODD){
            ODD = false;
            auto itr = prev(depth.end());
            int a = *itr;
            a--;
            depth.erase(itr);
            depth.insert(a);
            depth.erase(0);
            ans++;
            continue;
        }else{
            ODD = true;
            auto itr = depth.begin();
            depth.erase(itr);
            ans++;
            continue;
        }
    }
    cout << ans << endl;
}
