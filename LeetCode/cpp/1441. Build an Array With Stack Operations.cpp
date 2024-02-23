class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
        int current = 1;

        for (int num : target) {
            while (current < num) {
                operations.push_back("Push");
                operations.push_back("Pop");
                current++;
            }
            operations.push_back("Push");
            current++;
        }

        return operations;
    }
};