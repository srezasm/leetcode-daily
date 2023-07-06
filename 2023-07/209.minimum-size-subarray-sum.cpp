// 2023-07-06

/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (45.20%)
 * Likes:    10403
 * Dislikes: 292
 * Total Accepted:    756.3K
 * Total Submissions: 1.6M
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of positive integers nums and a positive integer target,
 * return the minimal length of a subarray whose sum is greater than or equal
 * to target. If there is no such subarray, return 0 instead.
 *
 *
 * Example 1:
 *
 *
 * Input: target = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: The subarray [4,3] has the minimal length under the problem
 * constraint.
 *
 *
 * Example 2:
 *
 *
 * Input: target = 4, nums = [1,4,4]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: target = 11, nums = [1,1,1,1,1,1,1,1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= target <= 10^9
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 *
 *
 *
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution of which the time complexity is O(n log(n)).
 */

#include <limits.h>
#include <vector>
using namespace std;

// class Solution {
//    public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int l = 0;
//         int cur = 0;
//         int ans = INT_MAX;
//         int n = nums.size();

//         for (int r = 0; r < n; r++) {
//             cur += nums[r];
//             while(cur >= target) {
//                 ans = min(ans, r - l + 1);
//                 cur -= nums[l];
//                 l++;
//             }
//         }

//         return ans == INT_MAX ? 0 : ans;
//     }
// };

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int r = n;
        int l = 0;
        int mid;
        while(l <= r) {
            mid = (l + r) / 2;
            
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v = {1,4,4};
    Solution().minSubArrayLen(4, v);
    return 0;
}
