// 2023-07-04

/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (58.77%)
 * Likes:    6584
 * Dislikes: 594
 * Total Accepted:    463K
 * Total Submissions: 767.8K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given an integer array nums where every element appears three times except
 * for one, which appears exactly once. Find the single element and return it.
 *
 * You must implement a solution with a linear runtime complexity and use only
 * constant extra space.
 *
 *
 * Example 1:
 * Input: nums = [2,2,3,2]
 * Output: 3
 * Example 2:
 * Input: nums = [0,1,0,1,0,1,99]
 * Output: 99
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * Each element in nums appears exactly three times except for one element
 * which appears once.
 *
 *
 */

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        long long ans = 0;
        for (const int& i : nums) {
            switch (mp[i]) {
                case 0:
                    ans += i;
                    break;
                case 1:
                    ans -= i;
                case 2:
                    break;
            }
            mp[i]++;
        }
        return ans;
    }
};

// // Someones interesting answer
// class Solution {
//    public:
//     int singleNumber(vector<int>& nums) {
//         // First time number appear -> save it in "ones"
//         // Second time -> clear "ones" but save it in "twos" for later check
//         // Third time -> try to save in "ones" but value saved in "twos" clear it.

//         int ones = 0, twos = 0;
//         for (const int& i: nums) {
//             // IF the set "ones" does not have A[i]
//             //  Add A[i] to the set "ones" if and only if its not there in set "twos"
//             // ELSE
//             // Remove it from the set "ones"
//             ones = (ones ^ i) & ~twos;
//             // IF the set "twos" does not have A[i]
//             // Add A[i] to the set "twos" if and only if its not there in set "ones"
//             // ELSE
//             // Remove it from the set "twos"
//             twos = (twos ^ i) & ~ones;
//         }
//         return ones;
//     }
// };
