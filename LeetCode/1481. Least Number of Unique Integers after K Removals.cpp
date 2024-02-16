class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(int &i : arr) mp[i]++;

        vector<int> v;
        for(auto &[key, value] : mp) v.push_back(value);
        sort(v.begin(), v.end());
        for(int i = 0 ; i < v.size() ; i++){
            if(k >= v[i]) k -= v[i];
            else return v.size() - i;
        }
        return 0;
    }
};