class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord)) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);

        int step = 1;

        while (!q.empty()) {

            int s = q.size();

            while (s--) {

                string word = q.front();
                q.pop();

                if (word == endWord) {
                    return step;
                }

                for (int i = 0; i < word.size(); i++) {

                    char original = word[i];

                    for (char c = 'a'; c <= 'z'; c++) {

                        word[i] = c;

                        if (st.count(word)) {
                            q.push(word);
                            st.erase(word);
                        }
                    }

                    word[i] = original; // put originaal character to go next step  like if hot nd we choose for h ... nd what if there is no for h ... then it must O OR T then it nessecary to 1st is H which is original so ..thats why ...             }
                }
            }

            step++;   
        }

        return 0;
    }
};