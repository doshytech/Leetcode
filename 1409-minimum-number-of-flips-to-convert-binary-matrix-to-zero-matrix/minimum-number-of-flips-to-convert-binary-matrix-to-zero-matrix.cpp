const int INF = 1e9;

class Solution {
public:
    int minFlips(vector<vector<int>>& initial_grid) {
        int n = initial_grid.size(), m = initial_grid[0].size();
         if (n > m) {
        vector<vector<int>> transposed_grid(m, vector<int>(n));
        for(int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                transposed_grid[j][i] = initial_grid[i][j];
            }
        }
        swap(n, m);
        initial_grid = transposed_grid;
    }

    int min_clicks = INF;

    for (int i = 0; i < (1 << n); ++i) {
        vector<vector<int>> temp_grid = initial_grid;
        int current_clicks = 0;

        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                apply_click(j, 0, n, m, temp_grid);
                current_clicks++;
            }
        }

        for (int c = 1; c < m; ++c) {
            for (int r = 0; r < n; ++r) {
                if (temp_grid[r][c - 1] == 1) {
                    apply_click(r, c, n, m, temp_grid);
                    current_clicks++;
                }
            }
        }

        bool possible = true;
        for (int r = 0; r < n; ++r) {
            if (temp_grid[r][m - 1] == 1) {
                possible = false;
                break;
            }
        }

        if (possible) {
            min_clicks = min(min_clicks, current_clicks);
        }
    }

    if (min_clicks == INF) {
        return -1;
    } 
    return min_clicks;

    }
    void apply_click(int r, int c, int R, int C, vector<vector<int>>& grid) {
        int dr[] = {0, 0, 0, 1, -1};
        int dc[] = {0, 1, -1, 0, 0};
        for (int i = 0; i < 5; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                grid[nr][nc] ^= 1;
            }
        }
    }


};