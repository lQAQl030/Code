class Solution {
public:
    int Find(int a, vector<int>& parent){
        if(parent[a] != a) return Find(parent[a], parent);
        return parent[a];
    }

    void Union(int a, int b, vector<int>& parent){
        int x = Find(a, parent), y = Find(b, parent);
        if(x == y) return;

        parent[y] = x;
        return;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> parent(n);
        for(int i = 0 ; i < n ; i++) parent[i] = i;
        for(auto &v: edges) Union(v[0], v[1], parent);
        return Find(source, parent) == Find(destination, parent);
    }
};