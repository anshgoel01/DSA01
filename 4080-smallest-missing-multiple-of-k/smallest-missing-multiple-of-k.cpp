class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;

        for(auto x : nums){
            if(x%k == 0){
                st.insert(x/k);
            }
        }
        int x = 1;
            while(st.find(x) != st.end()){
                x++;
        }
        return x * k;
    }
};