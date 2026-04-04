class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (target < -sum or target > sum) { 
            return 0;
        }
        int n = nums.size();
        vector<vector<int>> dp (n + 1, vector<int> (2 * sum + 1));
        dp[0][0 + sum] = 1;
        for (int i = 1; i <= n; i++) {
            int c = nums[i - 1];
            for (int j = 0; j <= 2 * sum; j++) {
                if (j - c >= 0) {
                    dp[i][j] += dp[i - 1][j - c]; 
                } 
                if (j + c <= 2 * sum) {
                    dp[i][j] += dp[i - 1][j + c];
                }
            }
        }
        return dp[n][sum + target];
    }
};
