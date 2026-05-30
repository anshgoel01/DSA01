class Solution {
public:
    struct SegTree {
        int n;
        vector<int> st;

        SegTree(int n) : n(n) {
            st.assign(4 * n + 4, 0);
        }

        void update(int p, int val, int node, int l, int r) {
            if (l == r) {
                st[node] = val;
                return;
            }

            int mid = (l + r) >> 1;

            if (p <= mid)
                update(p, val, node << 1, l, mid);
            else
                update(p, val, node << 1 | 1, mid + 1, r);

            st[node] = max(st[node << 1], st[node << 1 | 1]);
        }

        void update(int p, int val) {
            update(p, val, 1, 0, n);
        }

        int query(int L, int R, int node, int l, int r) {
            if (R < l || r < L) return 0;
            if (L <= l && r <= R) return st[node];

            int mid = (l + r) >> 1;

            return max(
                query(L, R, node << 1, l, mid),
                query(L, R, node << 1 | 1, mid + 1, r)
            );
        }

        int query(int L, int R) {
            if (L > R) return 0;
            return query(L, R, 1, 0, n);
        }
    };

    vector<bool> getResults(vector<vector<int>>& queries) {
        int MX = 50000;

        set<int> pos;
        pos.insert(0);
        pos.insert(MX);

        vector<int> obstacles;

        for (auto &q : queries) {
            if (q[0] == 1) {
                pos.insert(q[1]);
                obstacles.push_back(q[1]);
            }
        }

        SegTree seg(MX);

        auto buildGap = [&](int r, int gap) {
            seg.update(r, gap);
        };

        for (auto it = next(pos.begin()); it != pos.end(); ++it) {
            int r = *it;
            int l = *prev(it);
            buildGap(r, r - l);
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; --i) {

            auto &q = queries[i];

            if (q[0] == 2) {

                int x = q[1];
                int sz = q[2];

                auto it = prev(pos.upper_bound(x));

                int bestGap = seg.query(0, x);
                int tailGap = x - *it;

                ans.push_back(max(bestGap, tailGap) >= sz);

            } else {

                int p = q[1];

                auto it = pos.find(p);

                int L = *prev(it);
                int R = *next(it);

                pos.erase(it);

                seg.update(R, R - L);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};