class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circle = 0, square = 0;
        for(int i : students){
            if(i == 0) circle++;
            else square++;
        }

        for(int i : sandwiches){
            if(i == 0){
                if(circle > 0) circle--;
                else break;
            }else{
                if(square > 0) square--;
                else break;
            }
        }

        return max(circle, square);
    }
};