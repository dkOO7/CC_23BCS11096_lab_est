class Solution {
public:
    int f(int amount, vector<int>& coins, vector<int>& dp) {
        if (amount == 0) return 0;
        if (amount < 0) return 1e9;
        if (dp[amount] != -1) return dp[amount];
        int ans = 1e9;
        for (int c : coins) ans = min(ans, 1 + f(amount - c, coins, dp));
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int res = f(amount, coins, dp);
        return res >= 1e9 ? -1 : res;
    }
};
