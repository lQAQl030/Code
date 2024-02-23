// Divide and concuer O(nlogn)
class Solution {
public:
    int findmid(vector<int>& nums, int low, int mid, int high){
        int left_sum = -1000000, right_sum = -1000000, sum = 0;
        for(int i = mid ; i >= low ; i--){
            sum += nums[i];
            if(sum > left_sum) left_sum = sum;
        }

        sum = 0;
        for(int i = mid+1 ; i <= high ; i++){
            sum += nums[i];
            if(sum > right_sum) right_sum = sum;
        }

        return left_sum + right_sum;
    }

    int findmax(vector<int>& nums, int low, int high){
        if(low == high) return nums[low];
        int mid = (low + high) / 2;

        int left = findmax(nums, low, mid);
        int right = findmax(nums, mid+1, high);
        int cross = findmid(nums, low, mid, high);

        return max(left, max(right, cross));
    }

    int maxSubArray(vector<int>& nums) {
        return findmax(nums, 0, nums.size()-1);
    }
};

// DP O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // speed up
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = nums.size(), sum = 0, max_sum = nums[0];
        for (int i = 0 ; i < n ; i++) {
            sum += nums[i];
            max_sum = max(max_sum, sum);
            if (sum < 0) sum = 0;
        }
        return max_sum;
    }
};