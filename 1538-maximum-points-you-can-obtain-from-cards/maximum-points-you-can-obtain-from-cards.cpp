// class Solution {
// public:

//     int sumLeft(vector<int>& cardPoints, int k){
//         int Lsum = 0;
//         int n  = cardPoints.size();

//         for(int i = 0; i < k; i++){
//             if(k > 0){
//                 Lsum += cardPoints[i];
//                 k--;               
//             }
//         }
//         return Lsum;
//     }

//         int sumRight(vector<int>& cardPoints, int k){
//         int Rsum = 0;
//         int n = cardPoints.size();

//         for(int i = n-1; i >= n; i--){
//             if(k > 0){
//                 Rsum += cardPoints[i];
//                 k--;
//             }
//         }
//         return Rsum;
//     }
//     int maxScore(vector<int>& cardPoints, int k) {
//         int Lmax = sumRight(cardPoints,k);
//         int Rmax = sumLeft(cardPoints,k);

//         return max(Lmax,Rmax);

//     }
// };



class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        int leftSum = 0;
        for(int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }

        int maxScore = leftSum;
        int rightSum = 0;

        for(int i = k - 1; i >= 0; i--) {
            leftSum -= cardPoints[i];
            rightSum += cardPoints[n - (k - i)];

            maxScore = max(maxScore, leftSum + rightSum);
        }

        return maxScore;
    }
};