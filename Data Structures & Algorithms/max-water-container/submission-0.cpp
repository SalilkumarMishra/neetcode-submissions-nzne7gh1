class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int h = min(heights[left], heights[right]);
            int width = right - left;
            int area = h * width;

            maxArea = max(maxArea, area);

            // Move the shorter line
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};