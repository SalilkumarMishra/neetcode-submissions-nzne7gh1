class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        
        int longest = 0;
        
        for (int num : s) {
            // only start if it's the beginning
            if (s.find(num - 1) == s.end()) {
                
                int current = num;
                int length = 1;
                
                // expand sequence
                while (s.find(current + 1) != s.end()) {
                    current++;
                    length++;
                }
                
                longest = max(longest, length);
            }
        }
        
        return longest;
    }
};