class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;
        vector<int> pickup(3);
        for(int i = 0 ; i < garbage.size() ; i++){
            for(char c : garbage[i]){
                ans++;
                if(c == 'M') pickup[0] = i;
                else if(c == 'P') pickup[1] = i;
                else pickup[2] = i;
            }
        }

        while(pickup[0] > 0) ans += travel[--pickup[0]];
        while(pickup[1] > 0) ans += travel[--pickup[1]];
        while(pickup[2] > 0) ans += travel[--pickup[2]];
        return ans;
    }
};