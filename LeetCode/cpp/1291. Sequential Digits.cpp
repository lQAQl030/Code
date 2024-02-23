class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789";
        vector<int> ans;
        for(int digit = 2 ; digit < 10 ; digit++){
            for(int left = 0 ; left < 10 - digit ; left++){
                int num = stoi(str.substr(left, digit));
                if(low <= num && num <= high) ans.push_back(num);
            }
        }
        return ans;
    }
};