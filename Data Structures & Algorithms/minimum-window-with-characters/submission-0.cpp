class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        
        // Step 1: count frequency of t
        for(char c : t) {
            need[c]++;
        }

        int have = 0;
        int needCount = need.size();

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for(int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;

            // Check if current char satisfies need
            if(need.count(c) && window[c] == need[c]) {
                have++;
            }

            // Try to shrink window
            while(have == needCount) {
                // Update result
                if((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left char
                char leftChar = s[left];
                window[leftChar]--;

                if(need.count(leftChar) && window[leftChar] < need[leftChar]) {
                    have--;
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};