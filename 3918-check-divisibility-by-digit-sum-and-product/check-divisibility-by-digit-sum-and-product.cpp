class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int multiply = 1;

        for(int i = n; i > 0; i /= 10){
            const int r = i % 10;
            sum+=r;
            multiply*=r;
        }
        return n%(sum+multiply) == 0;
    }
};