class Solution {
public:

    vector<int>findNSE(vector<int> &arr){
        int n  = arr.size();
        stack<int> st;
        vector<int> nse(n);

        for(int i  = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;

    }
    vector<int>findPSE(vector<int> &arr){
        int n  = arr.size();
        stack<int> st;
        vector<int> pse(n);

        for(int i = 0; i <= n-1; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;

    }
    vector<int>findNGE(vector<int> &arr){
        int n  = arr.size();
        stack<int> st;
        vector<int> nge(n);

        for(int i  = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;

    }
    vector<int>findPGE(vector<int> &arr){
        int n  = arr.size();
        stack<int> st;
        vector<int> pge(n);

        for(int i = 0; i <= n-1; i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;

    }
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        // long long ans = 0;


        vector<int> nge = findNGE(nums);
        vector<int> pge = findPGE(nums);

        long long maxSUM = 0;

        for(int i  = 0; i < n; i++){
            long long maxleft = i - pge[i];
            long long maxright = nge[i] - i;

            maxSUM += 1LL * nums[i] * maxleft * maxright;
        }



        vector<int> nse = findNSE(nums);
        vector<int> pse = findPSE(nums);

        long long minSUM = 0;

        for(int i  = 0; i < n; i++){

            long long minleft = i - pse[i];
            long long minright = nse[i] - i;

            minSUM += 1LL * nums[i] * minleft * minright;
        }

        return maxSUM - minSUM;
    }
};