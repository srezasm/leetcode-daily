// 2023-06-16 (Just copy pasted to keep the streak)

/*
 * @lc app=leetcode id=1569 lang=cpp
 *
 * [1569] Number of Ways to Reorder Array to Get Same BST
 *
 * https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/description/
 *
 * algorithms
 * Hard (47.72%)
 * Likes:    1083
 * Dislikes: 141
 * Total Accepted:    26.5K
 * Total Submissions: 46.5K
 * Testcase Example:  '[2,1,3]'
 *
 * Given an array nums that represents a permutation of integers from 1 to n.
 * We are going to construct a binary search tree (BST) by inserting the
 * elements of nums in order into an initially empty BST. Find the number of
 * different ways to reorder nums so that the constructed BST is identical to
 * that formed from the original array nums.
 *
 *
 * For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left
 * child, and 3 as a right child. The array [2,3,1] also yields the same BST
 * but [3,2,1] yields a different BST.
 *
 *
 * Return the number of ways to reorder nums such that the BST formed is
 * identical to the original BST formed from nums.
 *
 * Since the answer may be very large, return it modulo 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,1,3]
 * Output: 1
 * Explanation: We can reorder nums to be [2,3,1] which will yield the same
 * BST. There are no other ways to reorder nums which will yield the same
 * BST.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,4,5,1,2]
 * Output: 5
 * Explanation: The following 5 arrays will yield the same BST:
 * [3,1,2,4,5]
 * [3,1,4,2,5]
 * [3,1,4,5,2]
 * [3,4,1,2,5]
 * [3,4,1,5,2]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,2,3]
 * Output: 0
 * Explanation: There are no other orderings of nums that will yield the same
 * BST.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= nums.length
 * All integers in nums are distinct.
 *
 *
 */

#include <vector>
using namespace std;

class Solution {
    vector<vector<long long>> dp;
    long long MOD = 1e9 + 7;

    unsigned long long solve(vector<int>& nums) {
        if (nums.size() <= 1)
            return 1;
        vector<int> l, r;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[0])
                r.push_back(nums[i]);
            else
                l.push_back(nums[i]);
        }
        int n = l.size(), m = r.size();
        return solve(l) * solve(r) % MOD * dp[n + m][n] % MOD;
    }

   public:
    int numOfWays(vector<int>& nums) {
        dp = vector<vector<long long>>(nums.size() + 1,
                                       vector<long long>(nums.size() + 1, 0));
        for (int i = 1; i < nums.size() + 1; ++i) {
            dp[i][0] = 1;
            dp[i][1] = i;
            dp[i][i - 1] = i;
            dp[i][i] = 1;
        }
        for (int i = 2; i < nums.size() + 1; ++i) {
            for (int j = 2; j < nums.size() + 1; ++j) {
                if (i >= j)
                    dp[i][j] =
                        (dp[i - 1][j - 1] % MOD + dp[i - 1][j] % MOD) % MOD;
                else
                    break;
            }
        }
        return solve(nums) - 1;
    }
};
