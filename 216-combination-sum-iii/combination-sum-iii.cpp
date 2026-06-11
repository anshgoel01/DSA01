class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(int nums, vector<int>&curr, int k, int n){
        if(n == 0 && curr.size() == k){
            ans.push_back(curr);
            return;
        }
        if(n < 0 || curr.size() > k || nums > 9){
            return;
        }
        curr.push_back(nums);
        backtrack(nums+1,curr,k,n-nums);
        curr.pop_back();
        backtrack(nums+1,curr,k,n);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        backtrack(1,curr,k,n);
        return ans;

    }
};