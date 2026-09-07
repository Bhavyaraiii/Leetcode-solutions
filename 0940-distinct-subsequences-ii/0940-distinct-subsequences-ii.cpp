class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        // dp[i] = number of distinct non-empty subsequences
        // using characters up to current position
        vector<long long> dp(s.length() + 1, 0);

        // last[c] = dp value before the previous occurrence of c
        vector<long long> last(26, 0);

        for (int i = 1; i <= s.length(); i++) {
            int c = s[i - 1] - 'a';

            // Add current character to every previous subsequence
            // and also form the subsequence consisting only of c
            dp[i] = (2 * dp[i - 1] + 1) % MOD;

            // Remove duplicates created by previous occurrence
            dp[i] = (dp[i] - last[c] + MOD) % MOD;

            // Store current dp value
            last[c] = (dp[i - 1] + 1) % MOD;
        }

        return dp[s.length()];
    }
};