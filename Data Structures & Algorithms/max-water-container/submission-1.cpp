class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int l = 0, r = heights.size() - 1;
        while (l < r) { 
            int area = (r - l) * min(heights[l], heights[r]);
            ans = max(ans, area);
            if (heights[l] > heights[r])
                r -= 1;
            else 
                l += 1;
        }
        return ans;
    }
};