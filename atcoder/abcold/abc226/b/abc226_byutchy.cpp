#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct bin_search_tree{
    struct node;
    using np = node*;
    np nil = (np)malloc(sizeof(node));
    np root = nil;
    vector<np> nodes;
    int sz = 0;

    struct node {
        T val;
        np l, r, par;
    };


    bin_search_tree(){
        nil->par = nil;
        nil->l = nil;
        nil->r = nil;
        return;
    }

    int size(){
        return sz;
    }

    np make_node(np parent, T v){
        sz++;
        bool is_left = (parent->val > v);
        np ch = (np)malloc(sizeof(node));
        nodes.push_back(ch);
        ch->r = nil;
        ch->l = nil;
        ch->val = v;
        ch->par = parent;
        if (is_left) parent->l = ch;
        else parent->r = ch;
        return ch;
    }

    np _find(T v, np p){
        if (p->val == v) return p;
        if (v > p->val && p->r != nil) return _find(v, p->r);
        if (v < p->val && p->l != nil) return _find(v, p->l);
        return p;
    }

    bool find(T v){
        if (root == nil) return 0;
        return (_find(v, root)->val == v);
    }

    np insert(T v){
        if (root == nil){
            sz++;
            root = (np)malloc(sizeof(node));
            root->r = nil;
            root->l = nil;
            root->par = nil;
            root->val = v;
            nodes.push_back(root);
            return root;
        }
        auto p = _find(v, root);
        if (p->val == v) return p;
        return make_node(p, v);
    }

    np erase(T v, np p){
        assert(p != nil);
        if (p->r == nil && p->l == nil){
            if (p->par->val > p->val) p->par->l = nil;
            else p->par->r = nil;
            sz--;
            return p->par;
        }
        else if (p->r == nil){
            if (p->par->val > p->val) p->par->l = p->l;
            else p->par->r = p->l;
            p->l->par = p->par;
            sz--;
            return p->par;
        }
        else if (p->l == nil){
            if (p->par->val > p->val) p->par->l = p->r;
            else p->par->r = p->r;
            p->r->par = p->par;
            sz--;
            return p->par;
        }
        else {
            p->val = p->r->val;
            return erase(v, p->r);
        }
    }

    bool erase(T v){
        auto p = _find(v, root);
        if (p->val != v) return 0;
        erase(v, p);
        return 1;
    }
};

int main(){
  int n;
  cin >> n;
  bin_search_tree<vector<int>> st;
  for (int i = 0; i < n; i++){
    int m;
    cin >> m;
    vector<int> v(m);
    for (int j = 0; j < m; j++) cin >> v[j];
    st.insert(v);
  }
  cout << st.size() << endl;
}
