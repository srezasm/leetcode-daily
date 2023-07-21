// 2023-07-21

/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (43.15%)
 * Likes:    5769
 * Dislikes: 233
 * Total Accepted:    176.1K
 * Total Submissions: 387.2K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * Given an integer array nums, return the number of longest increasing
 * subsequences.
 *
 * Notice that the sequence has to be strictly increasing.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3,5,4,7]
 * Output: 2
 * Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and
 * [1, 3, 5, 7].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,2,2,2,2]
 * Output: 5
 * Explanation: The length of the longest increasing subsequence is 1, and
 * there are 5 increasing subsequences of length 1, so output 5.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2000
 * -10^6 <= nums[i] <= 10^6
 *
 *
 */

#include <vector>
using namespace std;

class Solution {
   public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int max_len = 0;

        vector<pair<int, int>> dp(n, {1, 1});

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[i].first == dp[j].first + 1)
                        dp[i].second += dp[j].second;
                    if (dp[i].first < dp[j].first + 1)
                        dp[i] = {dp[j].first + 1, dp[j].second};
                }
            }

            if (max_len == dp[i].first)
                ans += dp[i].second;

            if (max_len < dp[i].first) {
                max_len = dp[i].first;
                ans = dp[i].second;
            }
        }

        return ans;
    }
};
