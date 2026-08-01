class Solution {
public:

    int solve(int left, int right, vector<int>& nums, vector<vector<int>>& dp){
        if(left == right) 
            return nums[left];

        if(dp[left][right] != -1) return dp[left][right];

        int Pickleft = nums[left] - solve(left + 1, right, nums, dp);
        int Pickright = nums[right] - solve(left, right - 1, nums, dp);

        return dp[left][right] =max(Pickleft,Pickright);
    }


    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        return solve(0, n-1, nums, dp) >= 0;
    }
};