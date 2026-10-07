class Solution {
public:

    unordered_set<string> st;

    void dfs(string &s, int index, int left, int right,
             int open, string &path) {

        // Reached end
        if(index == s.size()) {

            if(left == 0 && right == 0 && open == 0) {
                st.insert(path);
            }

            return;
        }

        char c = s[index];

        // Normal character
        if(c != '(' && c != ')') {

            path.push_back(c);

            dfs(s, index + 1, left, right, open, path);

            path.pop_back();
        }

        // '('
        else if(c == '(') {

            // OPTION 1: remove '('
            if(left > 0) {

                dfs(s, index + 1, left - 1, right,
                    open, path);
            }

            // OPTION 2: keep '('
            path.push_back('(');

            dfs(s, index + 1, left, right,
                open + 1, path);

            path.pop_back();
        }

        // ')'
        else {

            // OPTION 1: remove ')'
            if(right > 0) {

                dfs(s, index + 1, left, right - 1,
                    open, path);
            }

            // OPTION 2: keep ')'
            if(open > 0) {

                path.push_back(')');

                dfs(s, index + 1, left, right,
                    open - 1, path);

                path.pop_back();
            }
        }
    }


    vector<string> removeInvalidParentheses(string s) {

        int left = 0;
        int right = 0;

        // Find minimum number of '(' and ')' to remove
        for(char c : s) {

            if(c == '(') {
                left++;
            }

            else if(c == ')') {

                if(left > 0)
                    left--;
                else
                    right++;
            }
        }

        string path;

        dfs(s, 0, left, right, 0, path);

        vector<string> ans;

        for(auto x : st) {
            ans.push_back(x);
        }

        return ans;
    }
};