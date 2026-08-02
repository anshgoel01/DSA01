// class Solution {
// public:
//     int maxDistance(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         queue<vector<int>> q;
//         vector<vector<int>>vis(n,vector<int>(n,INT_MAX));

//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(grid[i][j]==1){
//                     q.push({0,i,j});
//                 }
//             }
//         }
//         if(q.empty() || q.size()==n*n) return -1;
//         int maxi=0;
//         int dx[4]={1,-1,0,0};
//         int dy[4]={0,0,-1,1};
//         while(!q.empty()){
//             auto it=q.front();
//             int x=it[1];
//             int y=it[2];
//             int dis=it[0];
//             q.pop();
//             for(int i=0;i<4;i++){
//                 int nx=x+dx[i];
//                 int ny=y+dy[i];
//                 if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0){
//                     if(dis+1<vis[nx][ny]){
//                         vis[nx][ny]=dis+1;
//                         maxi=max(maxi,vis[nx][ny]);
//                         q.push({vis[nx][ny],nx,ny});
//                     }
//                 }
//             }
//         }
//         return maxi;
//     }
// };

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        int n = grid.size();

        queue<pair<int,int>> q;

        int land = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==1){
                    q.push({i,j});
                    land++;
                }

            }
        }

        if(land==0 || land==n*n)
            return -1;

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        int distance = -1;

        while(!q.empty()){

            int size=q.size();

            distance++;

            while(size--){

                auto [row,col]=q.front();
                q.pop();

                for(int k=0;k<4;k++){

                    int nr=row+dr[k];
                    int nc=col+dc[k];

                    if(nr>=0 && nr<n &&
                       nc>=0 && nc<n &&
                       grid[nr][nc]==0){

                        grid[nr][nc]=1;
                        q.push({nr,nc});

                    }

                }

            }

        }

        return distance;
    }
};



