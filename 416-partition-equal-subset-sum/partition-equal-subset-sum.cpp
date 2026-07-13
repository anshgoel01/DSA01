class Solution {
public:
    bool f(vector<int>& nums, int target, int ind, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind == 0) return (nums[0] == target);
        if(dp[ind][target] != -1) return dp[ind][target];
        bool notTake = f(nums,target,ind-1,dp);
        bool take = false;
        if(target >= nums[ind]) take = f(nums,target-nums[ind],ind-1,dp);

        return dp[ind][target] = take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        int target = sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));

        if (sum % 2 == 1){
            return false;
        }else    
            return f(nums,target,n-1,dp);
    }
};