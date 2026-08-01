class Solution {
public:

    void dfs(vector<vector<int>>& image, int row, int col, int ogColor, int newColor){
        int n = image.size();
        int m = image[0].size();

        if(row < 0 || col < 0 || col >= m || row >= n)
            return;
        

        if(image[row][col] != ogColor)
        return;

        image[row][col] = newColor;

        dfs(image,row,col+1,ogColor,newColor);
        dfs(image,row,col-1,ogColor,newColor);
        dfs(image,row+1,col,ogColor,newColor);
        dfs(image,row-1,col,ogColor,newColor);
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ogColor = image[sr][sc];

        if(ogColor == color){
            return image;
        }

        dfs(image, sr, sc, ogColor, color);

        return image;
    }
};