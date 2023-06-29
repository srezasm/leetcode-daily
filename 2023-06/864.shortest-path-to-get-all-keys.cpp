// 2023-06-29
// skipped

/*
 * @lc app=leetcode id=864 lang=cpp
 *
 * [864] Shortest Path to Get All Keys
 *
 * https://leetcode.com/problems/shortest-path-to-get-all-keys/description/
 *
 * algorithms
 * Hard (45.57%)
 * Likes:    1735
 * Dislikes: 78
 * Total Accepted:    52.3K
 * Total Submissions: 101.2K
 * Testcase Example:  '["@.a..","###.#","b.A.B"]'
 *
 * You are given an m x n grid grid where:
 *
 *
 * '.' is an empty cell.
 * '#' is a wall.
 * '@' is the starting point.
 * Lowercase letters represent keys.
 * Uppercase letters represent locks.
 *
 *
 * You start at the starting point and one move consists of walking one space
 * in one of the four cardinal directions. You cannot walk outside the grid, or
 * walk into a wall.
 *
 * If you walk over a key, you can pick it up and you cannot walk over a lock
 * unless you have its corresponding key.
 *
 * For some 1 <= k <= 6, there is exactly one lowercase and one uppercase
 * letter of the first k letters of the English alphabet in the grid. This
 * means that there is exactly one key for each lock, and one lock for each
 * key; and also that the letters used to represent the keys and locks were
 * chosen in the same order as the English alphabet.
 *
 * Return the lowest number of moves to acquire all keys. If it is impossible,
 * return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = ["@.a..","###.#","b.A.B"]
 * Output: 8
 * Explanation: Note that the goal is to obtain all the keys not to open all
 * the locks.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = ["@..aA","..B#.","....b"]
 * Output: 6
 *
 *
 * Example 3:
 *
 *
 * Input: grid = ["@Aa"]
 * Output: -1
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 30
 * grid[i][j] is either an English letter, '.', '#', or '@'.
 * The number of keys in the grid is in the range [1, 6].
 * Each key in the grid is unique.
 * Each key in the grid has a matching lock.
 *
 *
 */

#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_map<char, int> key_bit;
        int bit_start = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (islower(grid[i][j]))
                    key_bit[grid[i][j]] = bit_start++;
            }
        }

        int form_end = (1 << bit_start) - 1;
        int form_size = (1 << bit_start);

        vector<vector<vector<bool>>> memo(m,
                                          vector<vector<bool>>(n, vector<bool>(form_size, false)));

        vector<int> start;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@')
                    start = {i, j, 0};  // 0 denoting no key state
            }
        }

        queue<vector<int>> q;
        q.push(start);
        int Ashish = 0;  // Step counter

        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                int row = q.front()[0];
                int col = q.front()[1];
                int form = q.front()[2];
                q.pop();

                // Check if out of bounds
                if (row < 0 || row >= m || col < 0 || col >= n)
                    continue;

                // Check if position is blocked
                if (grid[row][col] == '#')
                    continue;

                // Check if the key is required but not collected
                if (isupper(grid[row][col])) {
                    if ((form & (1 << key_bit[tolower(grid[row][col])])) == 0)
                        continue;
                }

                // If the position contains a key, collect it
                if (islower(grid[row][col])) {
                    form = form | (1 << key_bit[grid[row][col]]);
                }

                // If all keys are collected, return the step count
                if (form == form_end)
                    return Ashish;

                // If the position and form combination has been visited, continue to the next
                // iteration
                if (memo[row][col][form])
                    continue;
                memo[row][col][form] = true;

                // Add adjacent positions to the queue
                q.push({row + 1, col, form});
                q.push({row - 1, col, form});
                q.push({row, col + 1, form});
                q.push({row, col - 1, form});
            }
            Ashish++;  // Increment step count
        }
        return -1;
    }
};
