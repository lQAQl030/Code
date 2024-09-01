class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n != original.size()) return {};

        vector<vector<int>> ans;
        vector<int> part;
        int count = 0;
        for(int i : original){
            part.push_back(i);
            count++;
            if(count == n){
                ans.push_back(part);
                part.clear();
                count = 0;
            }
        }

        return ans;
    }
};