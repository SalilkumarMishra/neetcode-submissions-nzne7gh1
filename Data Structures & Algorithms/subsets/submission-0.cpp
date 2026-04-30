class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        // Add current subset to result
        result.push_back(current);

        for (int i = start; i < nums.size(); i++) {
            // Include nums[i]
            current.push_back(nums[i]);

            // Recurse for next elements
            backtrack(i + 1, nums, current, result);

            // Backtrack (remove last element)
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(0, nums, current, result);
        return result;
    }
};