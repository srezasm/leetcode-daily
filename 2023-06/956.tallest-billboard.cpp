// 2023-06-24

/*
 * @lc app=leetcode id=956 lang=cpp
 *
 * [956] Tallest Billboard
 *
 * https://leetcode.com/problems/tallest-billboard/description/
 *
 * algorithms
 * Hard (39.73%)
 * Likes:    1277
 * Dislikes: 41
 * Total Accepted:    24.9K
 * Total Submissions: 55.6K
 * Testcase Example:  '[1,2,3,6]'
 *
 * You are installing a billboard and want it to have the largest height. The
 * billboard will have two steel supports, one on each side. Each steel support
 * must be an equal height.
 *
 * You are given a collection of rods that can be welded together. For example,
 * if you have rods of lengths 1, 2, and 3, you can weld them together to make
 * a support of length 6.
 *
 * Return the largest possible height of your billboard installation. If you
 * cannot support the billboard, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: rods = [1,2,3,6]
 * Output: 6
 * Explanation: We have two disjoint subsets {1,2,3} and {6}, which have the
 * same sum = 6.
 *
 *
 * Example 2:
 *
 *
 * Input: rods = [1,2,3,4,5,6]
 * Output: 10
 * Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the
 * same sum = 10.
 *
 *
 * Example 3:
 *
 *
 * Input: rods = [1,2]
 * Output: 0
 * Explanation: The billboard cannot be supported, so we return 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= rods.length <= 20
 * 1 <= rods[i] <= 1000
 * sum(rods[i]) <= 5000
 *
 *
 */

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    int tallestBillboard(vector<int>& rods) {
        int sum = 0;
        for (int rod : rods) {
            sum += rod;
        }

        int dp[sum + 1];
        dp[0] = 0;

        for (int i = 1; i <= sum; i++)
            dp[i] = -1;

        for (int rod : rods) {
            int dpCopy[sum + 1];
            copy(dp, dp + (sum + 1), dpCopy);

            for (int i = 0; i <= sum - rod; i++) {
                if (dpCopy[i] < 0)
                    continue;

                dp[i + rod] = max(dp[i + rod], dpCopy[i]);

                dp[abs(i - rod)] =
                    max(dp[abs(i - rod)], dpCopy[i] + min(i, rod));
            }
        }

        return dp[0];
    }
};
