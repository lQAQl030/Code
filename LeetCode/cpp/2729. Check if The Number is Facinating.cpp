class Solution {
public:
    bool isFascinating(int n) {
        string str = to_string(n) + to_string(n*2) + to_string(n*3);
        sort(str.begin(), str.end());
        return str == "123456789";
    }
};

//fun one
class Solution {
public:
    bool isFascinating(int n) {
        return n == 192 || n == 219 || n==273 || n==327;
    }
};