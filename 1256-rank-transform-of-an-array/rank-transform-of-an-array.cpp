class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> s = arr;
        sort(s.begin(),s.end());

        unordered_map<int,int> rank;
        int currentRank = 1;

        for(int num : s){
            if(!rank.count(num)){
                rank[num] = currentRank++;
            }                                         
        }
        for(int &num : arr){
            num = rank[num];
        }
        return arr;
    }
};