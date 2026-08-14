class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int ans = 0;
        int l = 0;
        int r = 0;
        priority_queue<pair<int,int>>mx;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>mn;
        while(r < n){
           mx.push({nums[r],r});
           mn.push({nums[r],r});
           while(!mx.empty() && mx.top().second<l){
            mx.pop();
           }
           while(!mn.empty() && mn.top().second<l){
            mn.pop();
           }
           while(!mx.empty() && !mn.empty() && mx.top().first-mn.top().first>limit && l<=r){
            l++;

            while (!mx.empty() && mx.top().second < l)
                    mx.pop();

            while (!mn.empty() && mn.top().second < l)
                    mn.pop();
            
           }
           ans=max(ans,r-l+1);
           r++;
        }
        return ans;
    }
};