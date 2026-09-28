class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    int atMost(vector<int>& A, int k){
        int i = 0, res = 0;
        unordered_map<int, int> cnt;
        int n = A.size();
        for(int j = 0; j < n; ++j){
            if(!cnt[A[j]]++) k--;
            while(k < 0){
                if(!--cnt[A[i]]) k++;
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};