class Solution {
public:
    void backtrack(int index, vector<int>&arr, int target, vector<vector<int>>&ans, vector<int>&ds){
        if(index == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[index] <= target){
            ds.push_back(arr[index]);
            backtrack(index, arr, target-arr[index], ans, ds);
            ds.pop_back();
        }
        backtrack(index+1, arr, target, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        backtrack(0,candidates,target,ans,ds);

        return ans;
    }
};