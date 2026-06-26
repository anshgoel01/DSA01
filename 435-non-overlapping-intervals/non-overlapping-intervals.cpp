class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int cnt = 0;
        int prevEnd = intervals[0][1];

        for(int i = 1; i < n; i++){
        int currentStart = intervals[i][0];
            if(currentStart < prevEnd){
                cnt++;
                prevEnd = min(prevEnd,intervals[i][1]);
            }else{
                prevEnd = intervals[i][1];
            }
        }
        return cnt;
    }
};