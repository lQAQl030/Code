class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int first = coordinates[0] - 'a';
        int second = coordinates[1] - '1';
        return (first ^ second) & 1 == 1;
    }
};