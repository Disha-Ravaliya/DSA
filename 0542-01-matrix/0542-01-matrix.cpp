class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));

        vector<vector<int>>dist(n,vector<int>(m,0));

        for(int i =0; i <n;i++){
            for(int j =0; j<m ; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }else{
                    visited[i][j] = 0;
                }
            }
        }
// this for 
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps;

            for(int i =0; i <4; i++){
                int nrow = row + delrow[i]; // neighbour row
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow< n && ncol>=0 && ncol < m && visited[nrow][ncol] ==0){
                    visited[nrow][ncol] = 1;
                    q.push({{nrow,ncol},steps+1});
                } 
            }


        }
        return dist;
    }
};