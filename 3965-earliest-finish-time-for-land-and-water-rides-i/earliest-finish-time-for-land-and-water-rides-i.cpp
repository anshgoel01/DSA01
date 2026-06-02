class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans = INT_MAX;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                //Land -> Water
                int landfinish = landStartTime[i] + landDuration[i];
                int waterstart = max(landfinish,waterStartTime[j]);
                ans = min(ans,waterstart + waterDuration[j]);

                //Water -> Land
                int waterfinish = waterStartTime[j] + waterDuration[j];
                int landstart = max(waterfinish,landStartTime[i]);
                ans = min(ans,landstart + landDuration[i]);
            }
        }

        return ans;
        
    }
};