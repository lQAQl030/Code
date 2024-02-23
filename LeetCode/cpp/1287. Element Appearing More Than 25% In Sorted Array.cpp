class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int quarter = arr.size() / 4 + 1;
        for(int i = 0 ; i < arr.size() ; i++){
            int count = 1;
            while(i+1 < arr.size() && arr[i] == arr[i+1]){
                count++;
                i++;
            }
            if(count >= quarter) return arr[i];
        }
        return -1;
    }
};