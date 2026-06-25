class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] == target)
                pref[i + 1] = pref[i] + 1;
            else
                pref[i + 1] = pref[i] - 1;
        }

        int OFFSET = n + 1;
        vector<int> bit(2 * n + 5, 0);

        auto update = [&](int idx) {
            while (idx < bit.size()) {
                bit[idx]++;
                idx += idx & (-idx);
            }
        };

        auto query = [&](int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & (-idx);
            }
            return sum;
        };

        long long ans = 0;

        update(pref[0] + OFFSET);

        for (int i = 1; i <= n; i++) {
            int cur = pref[i] + OFFSET;

            ans += query(cur - 1);

            update(cur);
        }

        return ans;
    }
};