class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int row, int col){

        int n = grid.size();
        int m = grid[0].size();

        if(row < 0 || col < 0 || row >= n || col >=m)
        return;

        if(grid[row][col] == '0' || vis[row][col])
        return;

        vis[row][col] = true;

        dfs(grid,vis,row+1,col);
        dfs(grid,vis,row-1,col);
        dfs(grid,vis,row,col+1);
        dfs(grid,vis,row,col-1);

    }


    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int island = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if (grid[i][j] == '1' && !vis[i][j]){
                island++;

                dfs(grid, vis, i, j);
                }
            }
        }
        return island;
    }
};