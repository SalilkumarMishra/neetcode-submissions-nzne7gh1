class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            
            // If duplicate, shrink window
            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }

            // Add current character
            st.insert(s[right]);

            // Update max length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};