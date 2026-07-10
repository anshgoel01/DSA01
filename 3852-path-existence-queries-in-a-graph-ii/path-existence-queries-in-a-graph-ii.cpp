class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<pair<int,int>> a;
        for(int i = 0; i < n; i++)
            a.push_back({nums[i], i});

        sort(a.begin(), a.end());

        vector<int> pos(n);
        vector<int> val(n);

        for(int i = 0; i < n; i++){
            val[i] = a[i].first;
            pos[a[i].second] = i;
        }

        // next[i] = farthest index reachable in one edge
        vector<int> nxt(n);

        int r = 0;
        for(int i = 0; i < n; i++){
            while(r + 1 < n && val[r + 1] - val[i] <= maxDiff)
                r++;
            nxt[i] = r;
        }

        // Binary lifting
        int LOG = 20;
        vector<vector<int>> up(LOG, vector<int>(n));

        up[0] = nxt;

        for(int k = 1; k < LOG; k++){
            for(int i = 0; i < n; i++){
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for(auto &q : queries){

            int u = pos[q[0]];
            int v = pos[q[1]];

            if(u > v) swap(u, v);

            // Not connected
            if(nxt[u] == u && u != v){
                ans.push_back(-1);
                continue;
            }

            int cur = u;
            int steps = 0;

            for(int k = LOG - 1; k >= 0; k--){
                if(up[k][cur] < v){
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }

            if(cur < v){
                if(nxt[cur] == cur)
                    ans.push_back(-1);
                else
                    ans.push_back(steps + 1);
            }else{
                ans.push_back(steps);
            }
        }

        return ans;
    }
};