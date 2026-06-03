class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        long long minLandFinish = LLONG_MAX;
        long long minWaterFinish = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            minLandFinish = min(
                minLandFinish,
                (long long)landStartTime[i] + landDuration[i]
            );
        }

        for (int j = 0; j < m; j++) {
            minWaterFinish = min(
                minWaterFinish,
                (long long)waterStartTime[j] + waterDuration[j]
            );
        }

        long long ans = LLONG_MAX;

        // Land -> Water
        for (int j = 0; j < m; j++) {
            ans = min(
                ans,
                max(minLandFinish,
                    (long long)waterStartTime[j])
                + waterDuration[j]
            );
        }

        // Water -> Land
        for (int i = 0; i < n; i++) {
            ans = min(
                ans,
                max(minWaterFinish,
                    (long long)landStartTime[i])
                + landDuration[i]
            );
        }

        return (int)ans;
    }
};