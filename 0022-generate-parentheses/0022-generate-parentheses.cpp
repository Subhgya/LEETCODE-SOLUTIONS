
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        backtrack(ans, "", 0, 0, n);

        return ans;
    }

    void backtrack(vector<string>& ans, string curr,
                   int open, int close, int n) {

        // Base condition: generated 2*n characters
        if (curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Add opening bracket if available
        if (open < n) {
            backtrack(ans, curr + '(', open + 1, close, n);
        }

        // Add closing bracket only if valid
        if (close < open) {
            backtrack(ans, curr + ')', open, close + 1, n);
        }
    }
};
