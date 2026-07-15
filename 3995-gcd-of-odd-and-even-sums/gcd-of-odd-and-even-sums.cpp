class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumEven = 0;
        int sumOdd = 0;

        for(int i = 1; i <= 2*n; i+=2){           
            sumOdd += i;
        }
        for(int i = 0; i <= 2*n; i+=2){           
            sumEven += i;
        }

        return gcd(sumOdd,sumEven);
    }
};