// 2023-07-22

/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 *
 * https://leetcode.com/problems/knight-probability-in-chessboard/description/
 *
 * algorithms
 * Medium (52.07%)
 * Likes:    3283
 * Dislikes: 420
 * Total Accepted:    124.8K
 * Total Submissions: 226.9K
 * Testcase Example:  '3\n2\n0\n0'
 *
 * On an n x n chessboard, a knight starts at the cell (row, column) and
 * attempts to make exactly k moves. The rows and columns are 0-indexed, so the
 * top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).
 *
 * A chess knight has eight possible moves it can make, as illustrated below.
 * Each move is two cells in a cardinal direction, then one cell in an
 * orthogonal direction.
 *
 * Each time the knight is to move, it chooses one of eight possible moves
 * uniformly at random (even if the piece would go off the chessboard) and
 * moves there.
 *
 * The knight continues moving until it has made exactly k moves or has moved
 * off the chessboard.
 *
 * Return the probability that the knight remains on the board after it has
 * stopped moving.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3, k = 2, row = 0, column = 0
 * Output: 0.06250
 * Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight
 * on the board.
 * From each of those positions, there are also two moves that will keep the
 * knight on the board.
 * The total probability the knight stays on the board is 0.0625.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1, k = 0, row = 0, column = 0
 * Output: 1.00000
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 25
 * 0 <= k <= 100
 * 0 <= row, column <= n - 1
 *
 *
 */

#include <unordered_map>
using namespace std;

class Solution {
   private:
    unordered_map<int, unordered_map<int, unordered_map<int, double>>> dp;

   public:
    double knightProbability(int N, int K, int r, int c) {
        if (dp.count(r) && dp[r].count(c) && dp[r][c].count(K))
            return dp[r][c][K];

        if (r < 0 || r >= N || c < 0 || c >= N)
            return 0;

        if (K == 0)
            return 1;

        double total =
            knightProbability(N, K - 1, r - 1, c - 2) + knightProbability(N, K - 1, r - 2, c - 1) +
            knightProbability(N, K - 1, r - 1, c + 2) + knightProbability(N, K - 1, r - 2, c + 1) +
            knightProbability(N, K - 1, r + 1, c + 2) + knightProbability(N, K - 1, r + 2, c + 1) +
            knightProbability(N, K - 1, r + 1, c - 2) + knightProbability(N, K - 1, r + 2, c - 1);

        double res = total / 8;
        dp[r][c][K] = res;

        return res;
    }
};
