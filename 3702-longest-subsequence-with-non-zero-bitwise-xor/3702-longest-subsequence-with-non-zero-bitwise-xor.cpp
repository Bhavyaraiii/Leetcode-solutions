class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;

        for (int x : nums) {
            xr ^= x;
        }

        // Whole array already has non-zero XOR
        if (xr != 0) {
            return n;
        }

        // Total XOR is 0.
        // Check if there is any non-zero element.
        for (int x : nums) {
            if (x != 0) {
                return n - 1;
            }
        }

        // All elements are 0
        return 0;
    }
};