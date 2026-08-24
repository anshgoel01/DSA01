class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int right = 0;
        int left = n-1;
        int ans = 0;

        while(right < left){
            ans = max(ans, min(height[left],height[right]) * (left - right));
            
            if(height[right] < height[left]){
                right++;
            }else{
                left--;
            }

        }
        return ans;
    }
};