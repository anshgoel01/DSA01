class Solution {
public:
    int canEat(vector<int>&piles, int h, int k){
        long long hours = 0;
        for (int bananas : piles) {
            hours += (bananas + k - 1) / k;  // ceil(bananas / k)
        }
            return hours <= h;
    }


    
    int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
        while(low<high){
            int mid = (low + high) / 2;
            if(canEat(piles,h,mid))
               high = mid;
            else
               low = mid + 1;
        }
        return low;
    }

};