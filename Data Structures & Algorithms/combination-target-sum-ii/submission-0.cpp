class Solution {
public:
    vector<vector<int>> result;
    
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& curr) {
        if (target == 0) {
            result.push_back(curr);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            
            // Stop if number exceeds target
            if (candidates[i] > target) break;
            
            curr.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, curr);
            curr.pop_back(); // backtrack
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        backtrack(candidates, target, 0, curr);
        return result;
    }
};