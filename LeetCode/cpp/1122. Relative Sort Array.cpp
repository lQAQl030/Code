class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int h[1001] = {0};

        for(int i : arr1) h[i]++;

        int idx = 0;
        for(int &i : arr2){
            while(h[i]){
                arr1[idx++] = i;
                h[i]--;
            }
        }

        for(int i = 0 ; i < 1001 ; i++){
            while(h[i]--){
                arr1[idx++] = i;
            }
        }

        return arr1;
    }
};