class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // right[i] = number of characters from the suffix
        // of word2 that can be matched using word1[i+1...]
        vector<int> right(n, 0);

        int j = m - 1;
        int cnt = 0;

        for (int i = n - 1; i >= 0; i--) {
            right[i] = cnt;

            if (j >= 0 && word1[i] == word2[j]) {
                j--;
                cnt++;
            }
        }

        vector<int> ans;

        int j2 = 0;
        bool changed = false;

        for (int i = 0; i < n && j2 < m; i++) {

            // Exact match
            if (word1[i] == word2[j2]) {
                ans.push_back(i);
                j2++;
            }

            // Use the one allowed change
            else if (!changed && right[i] >= m - 1 - j2) {
                ans.push_back(i);
                j2++;
                changed = true;
            }
        }

        if (j2 == m)
            return ans;

        return {};
    }
};