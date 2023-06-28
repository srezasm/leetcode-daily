// 2023-06-28

/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 *
 * https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/
 *
 * algorithms
 * Easy (77.44%)
 * Likes:    4474
 * Dislikes: 118
 * Total Accepted:    339.5K
 * Total Submissions: 438.5K
 * Testcase Example:  '[[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]'
 *
 * Given a m x n matrix grid which is sorted in non-increasing order both
 * row-wise and column-wise, return the number of negative numbers in grid.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
 * Output: 8
 * Explanation: There are 8 negatives number in the matrix.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[3,2],[1,0]]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 100
 * -100 <= grid[i][j] <= 100
 *
 *
 *
 * Follow up: Could you find an O(n + m) solution?
 */

#include <vector>
using namespace std;

class Solution {
   public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int ans = 0;
        for (const auto& row : grid)
            for (int i = 0; i < m; i++)
                if (row[i] < 0) {
                    ans += m - i;
                    break;
                }

        return ans;
    }
};
