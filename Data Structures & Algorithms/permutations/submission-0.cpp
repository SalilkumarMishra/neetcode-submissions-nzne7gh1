class Solution {
public:
    void solve(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, vector<bool>& used) {
        // Base case
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;  // Skip already used elements

            // Choose
            used[i] = true;
            temp.push_back(nums[i]);

            // Explore
            solve(nums, temp, ans, used);

            // Backtrack
            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(), false);

        solve(nums, temp, ans, used);
        return ans;
    }
};