class Solution {
public:
    struct Node {
        int len, pref, suff, best;
        char left, right;
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;
        res.left = a.left;
        res.right = b.right;

        res.pref = a.pref;
        if (a.pref == a.len && a.right == b.left)
            res.pref = a.len + b.pref;

        res.suff = b.suff;
        if (b.suff == b.len && a.right == b.left)
            res.suff = b.len + a.suff;

        res.best = max(a.best, b.best);

        if (a.right == b.left)
            res.best = max(res.best, a.suff + b.pref);

        return res;
    }

    void build(int p, int l, int r) {
        if (l == r) {
            tree[p] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }

        int m = (l + r) / 2;
        build(p * 2, l, m);
        build(p * 2 + 1, m + 1, r);

        tree[p] = merge(tree[p * 2], tree[p * 2 + 1]);
    }

    void update(int p, int l, int r, int idx, char c) {
        if (l == r) {
            tree[p] = {1, 1, 1, 1, c, c};
            return;
        }

        int m = (l + r) / 2;

        if (idx <= m)
            update(p * 2, l, m, idx, c);
        else
            update(p * 2 + 1, m + 1, r, idx, c);

        tree[p] = merge(tree[p * 2], tree[p * 2 + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        this->s = s;

        int n = s.size();
        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};