#include <iostream>
#include <vector>

using namespace std;

class Solution {
    private:
        int dfs (vector<vector<int>>& grid, int i, int j) {
            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
                return 1;
            }
            if (grid[i][j] == -1) {
                return 0;
            }

            grid[i][j] = -1;

            return (dfs(grid, i + 1, j) +
                    dfs(grid, i - 1, j) +
                    dfs(grid, i, j + 1) +
                    dfs(grid, i, j - 1));
        }

    public:
    // Approach 1: Iterative and counter
        int islandPerimeter(vector<vector<int>>& grid) {
            int rows = grid.size();
            int cols = grid[0].size();
            int res = 0;

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == 1) {
                        res += 4;

                        if (i > 0 && grid[i - 1][j] == 1) {
                            res -= 2;
                        }
                        if (j > 0 && grid[i][j - 1] == 1) {
                            res -= 2;
                        }
                    }
                }
            }
            return res;
        }

    // Approach 2: dfs
        int islandPerimeter_2(vector<vector<int>>& grid) {
            int rows = grid.size();
            int cols = grid[0].size();
            int res = 0;

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == 1) {
                        res += dfs(grid, i, j);
                    }
                }
            }
            return res;
        }
};

main() {
    Solution s;
    vector<vector<int>> grid;

    // Case 1:
    grid = {
        {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}
    };
    cout << "Case 1: " << endl;
    cout << s.islandPerimeter(grid) << endl;

    // Case 2:
    grid = {
        {1}
    };
    cout << "Case 2: " << endl;
    cout << s.islandPerimeter(grid) << endl;
}