class Solution {
public:
    vector<string> result;

    void backtrack(string curr, int open, int close, int n) {
        // If the string length becomes 2*n, it's valid
        if (curr.length() == 2 * n) {
            result.push_back(curr);
            return;
        }

        // Add '(' if we still have opening brackets left
        if (open < n) {
            backtrack(curr + "(", open + 1, close, n);
        }

        // Add ')' only if it won't make it invalid
        if (close < open) {
            backtrack(curr + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return result;
    }
};