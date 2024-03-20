class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0) return tasks.size();

        vector<int> count(26);
        for(char c : tasks) count[c - 'A']++;
        sort(count.begin(), count.end());

        size_t ans = (count.back() - 1) * (n + 1);
        for(int i : count) ans += (i == count.back());

        return max(ans, tasks.size());
    }
};