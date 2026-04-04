class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (nums[0] < nums[n - 1] or n == 1) {
            return nums[0];
        }
        int l = 0, r = n - 1, ans = INT_MAX;
        while (l <= r) {
            if (nums[l] < nums[r]) {
                ans = min(ans, nums[l]);
                break;
            }
            int m = l + (r - l) / 2;
            ans = min(ans, nums[m]);
            if (nums[m] >= nums[l]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
};
