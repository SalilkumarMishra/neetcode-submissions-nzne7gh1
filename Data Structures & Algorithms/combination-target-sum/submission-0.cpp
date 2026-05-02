class Solution {
public:
    void backtrack(vector<int>& nums, int target, int index, 
                   vector<int>& current, vector<vector<int>>& result) {
        
        // Base case: valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        // If out of bounds or target negative
        if (target < 0 || index >= nums.size()) return;
        
        // Choice 1: Pick current element
        current.push_back(nums[index]);
        backtrack(nums, target - nums[index], index, current, result);
        current.pop_back();
        
        // Choice 2: Skip current element
        backtrack(nums, target, index + 1, current, result);
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        backtrack(nums, target, 0, current, result);
        
        return result;
    }
};