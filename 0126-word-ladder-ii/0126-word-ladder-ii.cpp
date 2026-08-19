class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void dfs(string word, string beginWord, vector<string>& path) {

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (string p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord))
            return {};

        queue<string> q;
        q.push(beginWord);

        unordered_map<string, int> dist;
        dist[beginWord] = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                string curr = q.front();
                q.pop();

                int currLevel = dist[curr];

                for (int i = 0; i < curr.size(); i++) {

                    char original = curr[i];

                    for (char c = 'a'; c <= 'z'; c++) {

                        if (c == original)
                            continue;

                        curr[i] = c;

                        if (!st.count(curr) && !dist.count(curr))
                            continue;

                        // First time reaching curr
                        if (!dist.count(curr)) {

                            dist[curr] = currLevel + 1;
                            q.push(curr);

                            parent[curr].push_back(
                                curr.substr(0, i) +
                                original +
                                curr.substr(i + 1)
                            );
                        }

                        // Another shortest path reaching curr
                        else if (dist[curr] == currLevel + 1) {

                            parent[curr].push_back(
                                curr.substr(0, i) +
                                original +
                                curr.substr(i + 1)
                            );
                        }
                    }

                    curr[i] = original;
                }
            }

            // We don't need to continue once endWord
            // has been reached at this level.
            if (dist.count(endWord))
                break;
        }

        if (!dist.count(endWord))
            return {};

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};