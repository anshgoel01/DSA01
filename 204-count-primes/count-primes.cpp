class Solution {
public:
    int countPrimes(int n) {

        if (n <= 2) return 0;

        vector<int> prime(n, 1);

        prime[0] = prime[1] = 0;

        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = 0;
                }
            }
        }

        int cnt = 0;

        for (int i = 2; i < n; i++) {
            if (prime[i]) cnt++;
        }

        return cnt;
    }
};