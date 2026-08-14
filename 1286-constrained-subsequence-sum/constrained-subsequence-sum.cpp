class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MIN;

        vector<int> dp(n);
        priority_queue<pair<int,int>> pq;

        for(int i = 0; i < n; i++){
            while(!pq.empty() && pq.top().second < i - k){
                pq.pop();
            }
            if(pq.empty()){
                dp[i] = nums[i];
            }else{
                dp[i] = nums[i] + max(0,pq.top().first);
            }

            pq.push({dp[i],i});

            ans = max(ans, dp[i]);
        }
        return ans;
    }
};