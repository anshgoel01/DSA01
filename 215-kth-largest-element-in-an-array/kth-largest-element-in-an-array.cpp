class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n  = nums.size();

        // step: 1
        for(int i = 0; i < k; i++){
            pq.push(nums[i]);
        }

        // step:2
        for(int i = k; i < n ; i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }

        int ans = pq.top();
        return ans;
    }
};