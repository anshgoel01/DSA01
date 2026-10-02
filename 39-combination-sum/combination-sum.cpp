class Solution {
public:
    void backtrack(int index, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& ds){
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[index] <= target){
            ds.push_back(candidates[index]);
            backtrack(index, candidates, target - candidates[index], ans, ds);
            ds.pop_back();
        }
        backtrack(index+1, candidates, target, ans, ds);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        backtrack(0,candidates,target,ans,ds);

        return ans;


    }
};