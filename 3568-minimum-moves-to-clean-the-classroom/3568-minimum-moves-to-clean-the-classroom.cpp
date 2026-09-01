class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        // Give each litter cell a bit
        vector<vector<int>> id(m, vector<int>(n, -1));
        int litterCount = 0;

        int sr = 0, sc = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        int fullMask = (1 << litterCount) - 1;

        // If there is no litter
        if (litterCount == 0)
            return 0;

        /*
            best[r][c][mask] =
            maximum remaining energy with which we have reached
            (r,c) having collected 'mask'.
        */
        vector<vector<vector<int>>> best(
            m, vector<vector<int>>(
                   n, vector<int>(1 << litterCount, -1)
               )
        );

        struct State {
            int r, c;
            int mask;
            int energy;
        };

        queue<State> q;

        best[sr][sc][0] = energy;
        q.push({sr, sc, 0, energy});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                State cur = q.front();
                q.pop();

                int r = cur.r;
                int c = cur.c;
                int mask = cur.mask;
                int e = cur.energy;

                if (mask == fullMask)
                    return moves;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Every move costs 1 energy
                    if (e == 0)
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }

                    // Reset energy on R
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    // Only continue if this state gives us
                    // more energy than previously seen.
                    if (ne > best[nr][nc][nmask]) {
                        best[nr][nc][nmask] = ne;
                        q.push({nr, nc, nmask, ne});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};