class Solution {
public:

    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visit){
        int n = isConnected.size();
        visit[node] = true;
        for(int i = 0; i < n; i++){
            if(isConnected[node][i] && !visit[i]){
                dfs(i, isConnected, visit);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int NOC = 0;
        vector<bool> vis(n);

        for(int i = 0;i < n;i++){
            if(!vis[i]){
                NOC++;
                dfs(i, isConnected, vis);
            }
        }
        return NOC;
    }
};