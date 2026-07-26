class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        // int max = 1;

        return max(
            nums[n-1] * nums[n-2] * nums[n-3],
            nums[0] * nums[1] * nums[n-1]
        );

            }
};

        // if(nums[0] < 0 && nums[1] < 0 && n-3){
        //     max = nums[n-1] * nums[n-2] * nums[n-3];
        // }

        // for(int i = 0; i < n; i++){
        //     max *= nums[i];
        // }
        // return max;
