class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {

        string start = "";

       
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                start += char(board[i][j] + '0');
            }
        }

        string target = "123450";

        
        if(start == target)
            return 0;

        
        vector<vector<int>> neighbors = {
            {1,3},
            {0,2,4},
            {1,5},
            {0,4},
            {1,3,5},
            {2,4}
        };

        queue<string> q;
        unordered_set<string> visited;

        q.push(start);
        visited.insert(start);

        int steps = 0;

        while(!q.empty()) {

            int size = q.size();

            
            while(size--) {

                string current = q.front();
                q.pop();

                if(current == target)
                    return steps;

                
                int zero = current.find('0');

                
                for(int next : neighbors[zero]) {

                    string newState = current;

                    swap(newState[zero], newState[next]);

                    
                    if(!visited.count(newState)) {

                        visited.insert(newState);
                        q.push(newState);
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};