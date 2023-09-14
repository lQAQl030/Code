class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26,0);
        for(int i = 0 ; i < s.length() ; i++){
            v[s[i]-'a']++;
        }
        sort(v.begin(), v.end(), greater<int>());
        int sum = 0;
        for(int i = 1 ; i < v.size() ; i++){
            while(v[i] >= v[i-1] && v[i] != 0){
                sum++;
                v[i]--;
            }
        }
        return sum;
    }
};