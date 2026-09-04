class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> maxLeft(n);
        vector<int> minRight(n);

        // Maximum from 0 to i
        maxLeft[0] = nums[0];

        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], nums[i]);
        }

        // Minimum from i to n-1
        minRight[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            minRight[i] = min(minRight[i + 1], nums[i]);
        }

        // Find first stable index
        for (int i = 0; i < n; i++) {
            int instability = maxLeft[i] - minRight[i];

            if (instability <= k) {
                return i;
            }
        }

        return -1;
    }
};