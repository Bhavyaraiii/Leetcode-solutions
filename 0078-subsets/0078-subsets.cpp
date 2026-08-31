class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& nums, int index, vector<int>& temp) {
        
        // Store current subset
        ans.push_back(temp);
        
        // Try adding every remaining element
        for (int i = index; i < nums.size(); i++) {
            
            // Include nums[i]
            temp.push_back(nums[i]);
            
            // Move to next element
            solve(nums, i + 1, temp);
            
            // Backtrack
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        
        solve(nums, 0, temp);
        
        return ans;
    }
};