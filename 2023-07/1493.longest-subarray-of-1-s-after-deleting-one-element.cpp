// 2023-07-05

/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 *
 * https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/
 *
 * algorithms
 * Medium (61.27%)
 * Likes:    2657
 * Dislikes: 47
 * Total Accepted:    117.5K
 * Total Submissions: 180.7K
 * Testcase Example:  '[1,1,0,1]'
 *
 * Given a binary array nums, you should delete one element from it.
 *
 * Return the size of the longest non-empty subarray containing only 1's in the
 * resulting array. Return 0 if there is no such subarray.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,0,1]
 * Output: 3
 * Explanation: After deleting the number in position 2, [1,1,1] contains 3
 * numbers with value of 1's.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1,1,1,0,1,1,0,1]
 * Output: 5
 * Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1]
 * longest subarray with value of 1's is [1,1,1,1,1].
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,1,1]
 * Output: 2
 * Explanation: You must delete one element.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 *
 *
 */

#include <vector>
using namespace std;

class Solution {
   public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int ans = 0;
        for (int i : nums) {
            if (i == 1)
                r++;
            else {
                ans = max(ans, r + l);
                l = r;
                r = 0;
            }
        }
        ans = max(ans, r + l);

        return (ans == nums.size()) ? ans - 1 : ans;
    }
};
