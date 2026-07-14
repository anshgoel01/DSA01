class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        vector<vector<int>> L(n + 1), R(n + 1);

        // Generate subset sums for left half
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0, bits = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += left[i];
                    bits++;
                }
            }
            L[bits].push_back(sum);
        }

        // Generate subset sums for right half
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0, bits = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += right[i];
                    bits++;
                }
            }
            R[bits].push_back(sum);
        }

        for (int i = 0; i <= n; i++) {
            sort(R[i].begin(), R[i].end());
        }

        int total = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;

        for (int cnt = 0; cnt <= n; cnt++) {
            for (int s1 : L[cnt]) {

                int need = n - cnt;
                auto &vec = R[need];

                int target = total / 2 - s1;

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    int sum = s1 + *it;
                    ans = min(ans, abs(total - 2 * sum));
                }

                if (it != vec.begin()) {
                    --it;
                    int sum = s1 + *it;
                    ans = min(ans, abs(total - 2 * sum));
                }
            }
        }

        return ans;
    }
};