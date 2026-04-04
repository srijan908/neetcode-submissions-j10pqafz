class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp (amount + 1);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            int c = coins[i];
            for (int j = c; j <= amount; j++) {
                if (dp[j - c] != INT_MAX) {
                    dp[j] += dp[j - c];
                }
            }
        }
        return dp[amount] == INT_MAX ? 0 : dp[amount];
    }
};
