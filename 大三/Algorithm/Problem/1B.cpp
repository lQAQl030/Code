#include<bits/stdc++.h>
using namespace std;

struct Node{
    int l = 0;
    int r = 0;
    Node* left = NULL;
    Node* right = NULL;
    vector<int> v;
    Node(){v.resize(5, INT_MAX);}
    Node(int l, int r): l(l), r(r){
        v.resize(5, INT_MAX);
    }
};

Node* buildST(vector<int> &a, int l, int r){
    Node* head = new Node(l, r);
    if(l == r){
        head->v[0] = a[l];
        return head;
    }
    int mid = (l + r) / 2;
    head->left = buildST(a, l, mid);
    head->right = buildST(a, mid+1, r);
    head->v.clear();
    merge(head->left->v.begin(), head->left->v.end(), head->right->v.begin(), head->right->v.end(), back_inserter(head->v));
    head->v.resize(5);
    return head;
}

vector<int> getK(Node* head, int l, int r){
    if(l <= head->l && head->r <= r) return head->v;
    if(head->r < l || r < head->l) return {};
    vector<int> lv, rv, ans;
    lv = getK(head->left, l, r);
    rv = getK(head->right, l, r);
    merge(lv.begin(), lv.end(), rv.begin(), rv.end(), back_inserter(ans));
    ans.resize(5);
    return ans;
}

void updateST(Node* head, vector<int> &a, int idx){
    if(head->r < idx || idx < head->l) return;
    if(head->l == head->r){
        head->v[0] = a[idx];
        return;
    }
    updateST(head->left, a, idx);
    updateST(head->right, a, idx);
    head->v.clear();
    merge(head->left->v.begin(), head->left->v.end(), head->right->v.begin(), head->right->v.end(), back_inserter(head->v));
    head->v.resize(5);
    return;
}

int main(){
    // freopen("out.txt", "w", stdout);
    int n,q,type,idx,v,l,r,k;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    Node* head = buildST(a, 0, n-1);
    for(int i = 0 ; i < q ; i++){
        cin >> type;
        if(type == 1){
            cin >> idx >> v;
            a[--idx] = v;
            updateST(head, a, idx);
        }else{
            cin >> l >> r >> k;
            cout << getK(head, l-1, r-1)[k-1] << "\n";
        }
    }

    return 0;
}