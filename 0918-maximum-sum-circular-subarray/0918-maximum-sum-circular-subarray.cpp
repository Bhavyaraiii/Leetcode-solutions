class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;

        int currMax = 0;
        int maxSum = nums[0];

        int currMin = 0;
        int minSum = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            
            currMax = max(x, currMax + x);
            maxSum = max(maxSum, currMax);

        
            currMin = min(x, currMin + x);
            minSum = min(minSum, currMin);

            totalSum += x;
        }

        
        if (maxSum < 0) {
            return maxSum;
        }

        return max(maxSum, totalSum - minSum);
    }
};