class Solution {
public:
    int pow2(int x) {return x*x;}

    int countLatticePoints(vector<vector<int>>& circles) {
        int count = 0;
        int y = 0;
        for(int x = 0 ; x <= 200 ; x++){
            for(y = 0 ; y <= 200 ; y++){
                for(vector<int> &v : circles){
                    if(pow2(x - v[0]) + pow2(y - v[1]) <= pow2(v[2])){
                        count++;
                        break;
                    }
                }
            }
        }
        return count;
    }
};