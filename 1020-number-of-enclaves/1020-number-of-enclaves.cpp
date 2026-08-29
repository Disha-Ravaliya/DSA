class Solution {
public:

    void dfs(int i , int j ,int n,int m,vector<vector<bool>>& vis ,vector<vector<int>>& grid){

        if(i<0 || i >=n || j <0 || j >=m || vis[i][j]== true || grid[i][j] !=1){
            return;
        }
        vis[i][j] = true;
        
        // left
        dfs(i+1,j,n,m,vis,grid);
        dfs(i,j+1,n,m,vis,grid);
        dfs(i-1,j,n,m,vis,grid);
        dfs(i,j-1,n,m,vis,grid);


    }


    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int count =0;

        // for 1st row
        for(int i =0; i <m;i++){
            if(grid[0][i] == 1){
                dfs(0,i,n,m,vis,grid);
            }
        }

        // for last row
        for(int i =0; i <m;i++){
            if(grid[n-1][i] == 1){
                dfs(n-1,i,n,m,vis,grid);
            }
        }

        // for 1st col
        for(int i =0; i <n;i++){
            if(grid[i][0] == 1){
                dfs(i,0,n,m,vis,grid);
            }
        }


        // for last col
        for(int i =0; i <n;i++){
            if(grid[i][m-1] == 1){
                dfs(i,m-1,n,m,vis,grid);
            }
        }

// now check for all index ..if visited then it from boundryes ..nd not then it is in middle

        for(int i=0; i <n ; i++){
            for(int j =0; j <m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                count++;
                }
            }
        }

return count;

    }
};