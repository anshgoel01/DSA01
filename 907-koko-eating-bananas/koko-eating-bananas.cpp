class Solution {
public:
    int caneat(vector<int>& piles, int h, int k){
        long long hr = 0;

        for(int bananas : piles){
            hr += (bananas + k - 1) / k;
        }
        return hr <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        while(low < high){
            int mid = low + (high - low) / 2;
            if(caneat(piles,h,mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};