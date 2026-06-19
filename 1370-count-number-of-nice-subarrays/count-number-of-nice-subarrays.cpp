class Solution {
public:

    int count(vector<int>& nums, int k){
        int n  = nums.size();
        int left = 0;
        int freq = 0;
        int count = 0;

        for(int right = 0; right < n; right++){
            if(nums[right] % 2 == 1){
                freq++;
            }
            
            while(freq > k){
                if(nums[left] % 2 == 1){
                    freq--;
                
            }
            left++;
        }
        count += (right - left + 1);
    }
        return count;
    }


    int numberOfSubarrays(vector<int>& nums, int k) {
        return count(nums,k) - count(nums,k -1);
    }
    
};