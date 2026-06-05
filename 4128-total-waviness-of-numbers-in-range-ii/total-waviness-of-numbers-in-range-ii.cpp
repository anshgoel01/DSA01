class Solution {
public:
    using ll = long long;

    struct Node {
        ll cnt;
        ll wave;
    };

    string s;
    Node dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    Node dfs(int pos, int prev1, int prev2,
             bool started, bool tight) {

        if (pos == s.size()) {
            return {1, 0};
        }

        if (vis[pos][prev1][prev2][started][tight]) {
            return dp[pos][prev1][prev2][started][tight];
        }

        vis[pos][prev1][prev2][started][tight] = true;

        int limit = tight ? s[pos] - '0' : 9;

        Node ans = {0, 0};

        for (int d = 0; d <= limit; d++) {

            bool ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node nxt = dfs(
                    pos + 1,
                    10,
                    10,
                    false,
                    ntight
                );

                ans.cnt += nxt.cnt;
                ans.wave += nxt.wave;
            }
            else {

                int extra = 0;

                if (started && prev2 != 10) {

                    bool peak =
                        (prev1 > prev2 && prev1 > d);

                    bool valley =
                        (prev1 < prev2 && prev1 < d);

                    if (peak || valley)
                        extra = 1;
                }

                int nprev2, nprev1;

                if (!started) {
                    nprev2 = 10;
                    nprev1 = d;
                } else {
                    nprev2 = prev1;
                    nprev1 = d;
                }

                Node nxt = dfs(
                    pos + 1,
                    nprev1,
                    nprev2,
                    true,
                    ntight
                );

                ans.cnt += nxt.cnt;
                ans.wave += nxt.wave + 1LL * extra * nxt.cnt;
            }
        }

        return dp[pos][prev1][prev2][started][tight] = ans;
    }

    long long solve(long long x) {

        if (x < 0) return 0;

        s = to_string(x);

        memset(vis, 0, sizeof(vis));

        Node res = dfs(0, 10, 10, false, true);

        return res.wave;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};