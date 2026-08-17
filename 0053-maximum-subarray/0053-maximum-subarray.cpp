class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxProd = nums[0];
        int currentProd = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currentProd = max(nums[i], currentProd + nums[i]);
            maxProd = max(maxProd, currentProd);
        }

        return maxProd;
    }
};

        
    
