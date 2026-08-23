class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        int n = prices.size();

        for(int i = 0; i < n; i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }
            else{
                maxProfit = max(maxProfit,prices[i] - minPrice);
            }
        }
            return maxProfit;
    }
};