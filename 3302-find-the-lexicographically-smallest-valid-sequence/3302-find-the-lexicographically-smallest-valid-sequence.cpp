class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // prev[c][i] = largest index <= i where word1[index] == c
        // -1 if it doesn't exist.
        vector<array<int, 26>> prev(n);

        array<int, 26> last;
        last.fill(-1);

        for (int i = 0; i < n; ++i) {
            last[word1[i] - 'a'] = i;
            prev[i] = last;
        }

        // exact[j] = rightmost possible first index of an exact
        // subsequence matching word2[j...].
        vector<int> exact(m + 1, -1);

        // one[j] = rightmost possible first index of a subsequence
        // matching word2[j...] with at most one mismatch.
        vector<int> one(m + 1, -1);

        // Empty suffix can start after the end.
        exact[m] = n;
        one[m] = n;

        for (int j = m - 1; j >= 0; --j) {
            int c = word2[j] - 'a';

            // Exact match:
            // choose the rightmost occurrence of word2[j]
            // before the first position of the remaining suffix.
            if (exact[j + 1] > 0) {
                exact[j] = prev[exact[j + 1] - 1][c];
            }

            // Use the one allowed mismatch at word2[j].
            int mismatchPos = -1;

            if (exact[j + 1] > 0) {
                int limit = exact[j + 1] - 1;

                // Find the rightmost position <= limit whose
                // character is NOT word2[j].
                for (int ch = 0; ch < 26; ++ch) {
                    if (ch == c) continue;
                    mismatchPos = max(mismatchPos,
                                      prev[limit][ch]);
                }
            }

            // Or match this character exactly and use the mismatch
            // somewhere later.
            int exactPos = -1;
            if (one[j + 1] > 0) {
                exactPos = prev[one[j + 1] - 1][c];
            }

            one[j] = max(mismatchPos, exactPos);
        }

        // No valid sequence.
        if (one[0] == -1)
            return {};

        vector<int> ans;

        int pos = 0;
        bool usedMismatch = false;

        for (int j = 0; j < m; ++j) {
            int c = word2[j] - 'a';

            /*
             * We want the SMALLEST possible index.
             *
             * If we take an exact match, the remaining suffix may
             * still use the mismatch.
             *
             * If we take a different character, the remaining suffix
             * must match exactly.
             */

            for (int i = pos; i < n; ++i) {
                bool can = false;
                bool mismatch = (word1[i] != word2[j]);

                if (mismatch) {
                    if (usedMismatch)
                        continue;

                    // After using mismatch, the rest must match exactly.
                    if (exact[j + 1] > i)
                        can = true;
                } else {
                    // Exact match. The rest may use <= 1 mismatch.
                    if (one[j + 1] > i)
                        can = true;
                }

                if (can) {
                    ans.push_back(i);
                    pos = i + 1;
                    usedMismatch |= mismatch;
                    break;
                }
            }

            if ((int)ans.size() != j + 1)
                return {};
        }

        return ans;
    }
};