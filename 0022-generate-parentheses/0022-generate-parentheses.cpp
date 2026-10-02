class Solution {
public:
    vector<string> ans;

    void backtrack(string current, int open, int close, int n) {
        // Complete valid string
        if (current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // Add '('
        if (open < n) {
            backtrack(current + "(", open + 1, close, n);
        }

        // Add ')' only when it won't make parentheses invalid
        if (close < open) {
            backtrack(current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return ans;
    }
};