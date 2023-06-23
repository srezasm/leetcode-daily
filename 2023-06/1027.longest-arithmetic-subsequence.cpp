// 2023-06-23

/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Subsequence
 *
 * https://leetcode.com/problems/longest-arithmetic-subsequence/description/
 *
 * algorithms
 * Medium (46.62%)
 * Likes:    3417
 * Dislikes: 152
 * Total Accepted:    117.9K
 * Total Submissions: 248.3K
 * Testcase Example:  '[3,6,9,12]'
 *
 * Given an array nums of integers, return the length of the longest arithmetic
 * subsequence in nums.
 *
 * Note that:
 *
 *
 * A subsequence is an array that can be derived from another array by deleting
 * some or no elements without changing the order of the remaining
 * elements.
 * A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value
 * (for 0 <= i < seq.length - 1).
 *
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,6,9,12]
 * Output: 4
 * Explanation:  The whole array is an arithmetic sequence with steps of length
 * = 3.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [9,4,7,2,10]
 * Output: 3
 * Explanation:  The longest arithmetic subsequence is [4,7,10].
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [20,1,15,3,10,5,8]
 * Output: 4
 * Explanation:  The longest arithmetic subsequence is [20,15,10,5].
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 1000
 * 0 <= nums[i] <= 500
 *
 *
 */

#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return n;

        int ans = 2;
        vector<unordered_map<int, int>> dp(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];

                if (dp[j].count(diff))
                    dp[i][diff] = dp[j][diff] + 1;
                else
                    dp[i][diff] = 2;

                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
};

// // Interesting answer I found on Submissions page
// class Solution {
//    public:
//     int longestArithSeqLength(vector<int>& nums) {
//         int out{1};
//         for (int i{0}; i < 501 / out; ++i)
//             for (int d[1001]{}, D[1001]{}; const auto& num : nums)
//                 out = max(
//                     {
//                         out,
//                         d[num + 500] = d[num - i + 500] + 1,
//                         D[num] = D[num + i] + 1
//                     }
//                 );
//         return out;
//     }
// };