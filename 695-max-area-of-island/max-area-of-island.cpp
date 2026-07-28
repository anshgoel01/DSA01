class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int row, int col){
        int n = grid.size();
        int m = grid[0].size();

        if(row < 0 || col < 0 || row >= n || col >= m)
        return 0;

        if(grid[row][col] == 0)
        return 0;

        if(vis[row][col])
        return 0;

        vis[row][col] = true;

        int area = 1;

        area += dfs(grid,vis,row+1,col);
        area += dfs(grid,vis,row-1,col);
        area += dfs(grid,vis,row,col+1);
        area += dfs(grid,vis,row,col-1);

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m,false));

        int maxArea = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int currentArea = dfs(grid, vis, i, j);

                    maxArea = max(maxArea,currentArea);
                }
            }
        }
        return maxArea;


    }
};