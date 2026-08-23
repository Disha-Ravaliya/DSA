class Solution {
public:

    
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int ans =0;
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<bool>>vis(n,vector<bool>(m,false));
            queue<pair<pair<int,int>, int>> q;  // pair of i , j.  and last int is for time // using this we can count easily time by time++ ....

        // every 2 store in queue and time o
        for(int i =0;i<n ; i++){
            for(int j =0; j<m ; j++){
                if(grid[i][j] == 2 && !vis[i][j]){
                    q.push({{i,j},0}); 
                    vis[i][j] = true;

                }

            }
        }

        //bfs logic
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;

            q.pop();
            ans = max(ans,time);


            //check for 4 padoshi
            if(i-1>=0 && !vis[i-1][j] && grid[i-1][j] ==1){           //top
                q.push({{i-1,j},time+1});
                vis[i-1][j] = true;
                 grid[i-1][j] = 2;

            }

            if(j+1<m && !vis[i][j+1] && grid[i][j+1] ==1){           //right
                q.push({{i,j+1},time+1});
                vis[i][j+1] = true;
                grid[i][j+1] = 2;

            }

            if(i+1<n && !vis[i+1][j] && grid[i+1][j] == 1){           //bottom
                q.push({{i+1,j},time+1});
                vis[i+1][j] = true;
                grid[i+1][j] = 2;

            }


            if(j-1>=0 && !vis[i][j-1] && grid[i][j-1] == 1){           //left
                q.push({{i,j-1},time+1});
                vis[i][j-1] = true;
                 grid[i][j-1] = 2;

            }
            

        }
    


        for(int i =0;i<n; i++){
            for(int j =0;j<m ; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
       
        return ans;






    
    }
};