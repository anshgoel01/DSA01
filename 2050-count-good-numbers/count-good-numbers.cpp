class Solution {
public:
 
const long long MOD = 1e9 + 7;

long long pow(long long x, long long n){
    long long ans = 1;

        while(n) {
            if(n & 1)
                ans = (ans * x) % MOD;

            x = (x * x) % MOD;

            n >>= 1;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n+1) / 2;
        long long oddPos = n / 2;

        long long evenWays = pow(5, evenPos);
        long long oddWays  = pow(4, oddPos);

        return (evenWays * oddWays) % MOD;
    }
};