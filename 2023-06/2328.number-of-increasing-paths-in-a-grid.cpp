// 2023-06-18

/*
 * @lc app=leetcode id=2328 lang=cpp
 *
 * [2328] Number of Increasing Paths in a Grid
 *
 * https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/description/
 *
 * algorithms
 * Hard (47.89%)
 * Likes:    1435
 * Dislikes: 32
 * Total Accepted:    42.5K
 * Total Submissions: 73.7K
 * Testcase Example:  '[[1,1],[3,4]]'
 *
 * You are given an m x n integer matrix grid, where you can move from a cell
 * to any adjacent cell in all 4 directions.
 *
 * Return the number of strictly increasing paths in the grid such that you can
 * start from any cell and end at any cell. Since the answer may be very large,
 * return it modulo 10^9 + 7.
 *
 * Two paths are considered different if they do not have exactly the same
 * sequence of visited cells.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[1,1],[3,4]]
 * Output: 8
 * Explanation: The strictly increasing paths are:
 * - Paths with length 1: [1], [1], [3], [4].
 * - Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
 * - Paths with length 3: [1 -> 3 -> 4].
 * The total number of paths is 4 + 3 + 1 = 8.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[1],[2]]
 * Output: 3
 * Explanation: The strictly increasing paths are:
 * - Paths with length 1: [1], [2].
 * - Paths with length 2: [1 -> 2].
 * The total number of paths is 2 + 1 = 3.
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 1000
 * 1 <= m * n <= 10^5
 * 1 <= grid[i][j] <= 10^5
 *
 *
 */

#include <vector>
using namespace std;

class Solution {
    int dp[1000][1000]{};
    int MOD{1000000007};

   public:
    int solve(vector<vector<int>>& grid, int i, int j, int prev) {
        if (i >= grid.size() || i < 0)
            return 0;
        if (j >= grid[0].size() || j < 0)
            return 0;
        if (prev >= grid[i][j])
            return 0;
        if (dp[i][j] > 0)
            return dp[i][j];
        int ans{1};
        prev = grid[i][j];
        ans = (ans + solve(grid, i + 1, j, prev)) % MOD;
        ans = (ans + solve(grid, i - 1, j, prev)) % MOD;
        ans = (ans + solve(grid, i, j + 1, prev)) % MOD;
        ans = (ans + solve(grid, i, j - 1, prev)) % MOD;
        return dp[i][j] = ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans{};
        for (int i = 0; i < rows; ++i)
            fill_n(&dp[i][0], cols, 0);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ans = (ans + solve(grid, i, j, 0)) % MOD;
            }
        }
        return ans;
    }
};