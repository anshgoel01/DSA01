class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // Prefix count of non-zero digits
        vector<int> prefCnt(n + 1, 0);

        // Prefix sum of digits
        vector<long long> prefSum(n + 1, 0);

        // Store all non-zero digits
        vector<int> digits;

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            prefCnt[i + 1] = prefCnt[i] + (d != 0);
            prefSum[i + 1] = prefSum[i] + d;

            if (d != 0)
                digits.push_back(d);
        }

        int m = digits.size();

        // Powers of 10
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // Prefix hash of concatenated non-zero digits
        vector<long long> hash(m + 1, 0);
        for (int i = 0; i < m; i++)
            hash[i + 1] = (hash[i] * 10 + digits[i]) % MOD;

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int left = prefCnt[l];
            int right = prefCnt[r + 1];
            int len = right - left;

            if (len == 0) {
                ans.push_back(0);
                continue;
            }

            long long x =
                (hash[right] - hash[left] * pow10[len] % MOD + MOD) % MOD;

            long long sum = prefSum[r + 1] - prefSum[l];

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};