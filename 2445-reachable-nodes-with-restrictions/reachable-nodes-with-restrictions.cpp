class Solution {
public:

    int dfs(int node, vector<vector<int>>& graph, vector<bool>& restricted, vector<bool>& visited){
        visited[node] = true;
        
        int count = 1;

        for(int neighbor : graph[node]){
            if(restricted[neighbor] || visited[neighbor]){
            continue;
            }
        count += dfs(neighbor,graph,restricted,visited);
        }
        return count;
    }



    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> graph(n);

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> isRestricted(n, false);

        for(auto node : restricted){
            isRestricted[node] = true;
        }

        vector<bool> visited(n, false);

        return dfs(0, graph, isRestricted, visited);
    }
};