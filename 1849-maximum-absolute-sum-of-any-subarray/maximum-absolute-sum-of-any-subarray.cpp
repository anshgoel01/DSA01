class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0;
        int minSum = 0;
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if(sum < 0){
                sum = 0;
            }
            sum += nums[i];
            maxSum = max(maxSum, sum);
        }

        sum = 0;

        for (int i = 0; i < n; i++) {
            if(sum > 0){
                sum = 0;
            }
            sum += nums[i];
            minSum = min(minSum, sum);
        }
        return max(maxSum, abs(minSum));
    }
};