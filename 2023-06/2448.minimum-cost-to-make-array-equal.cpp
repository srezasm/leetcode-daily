// 2023-06-21 (Just copy pasted to keep the streak on exam night)

/*
 * @lc app=leetcode id=2448 lang=cpp
 *
 * [2448] Minimum Cost to Make Array Equal
 *
 * https://leetcode.com/problems/minimum-cost-to-make-array-equal/description/
 *
 * algorithms
 * Hard (34.87%)
 * Likes:    1739
 * Dislikes: 21
 * Total Accepted:    41.7K
 * Total Submissions: 94.7K
 * Testcase Example:  '[1,3,5,2]\n[2,3,1,14]'
 *
 * You are given two 0-indexed arrays nums and cost consisting each of n
 * positive integers.
 *
 * You can do the following operation any number of times:
 *
 *
 * Increase or decrease any element of the array nums by 1.
 *
 *
 * The cost of doing one operation on the i^th element is cost[i].
 *
 * Return the minimum total cost such that all the elements of the array nums
 * become equal.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3,5,2], cost = [2,3,1,14]
 * Output: 8
 * Explanation: We can make all the elements equal to 2 in the following way:
 * - Increase the 0^th element one time. The cost is 2.
 * - Decrease the 1^st element one time. The cost is 3.
 * - Decrease the 2^nd element three times. The cost is 1 + 1 + 1 = 3.
 * The total cost is 2 + 3 + 3 = 8.
 * It can be shown that we cannot make the array equal with a smaller cost.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,2,2,2,2], cost = [4,2,8,1,3]
 * Output: 0
 * Explanation: All the elements are already equal, so no operations are
 * needed.
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums.length == cost.length
 * 1 <= n <= 10^5
 * 1 <= nums[i], cost[i] <= 10^6
 *
 *
 */

#include <math.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution {
   public:
    long long calc(vector<int>& nums, vector<int>& cost, long long median) {
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++)
            ans += abs(1ll * nums[i] - median) * (1ll * cost[i]);

        return ans;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long tot = 0;
        long long sum = 0;
        int n = nums.size();

        vector<pair<int, int>> vec;

        for (int i = 0; i < nums.size(); i++)
            vec.push_back({nums[i], cost[i]});

        sort(vec.begin(), vec.end());

        for (int i = 0; i < n; i++)
            sum += vec[i].second;

        long long median;
        int i = 0;

        while (tot < (sum + 1) / 2 && i < n) {
            tot += 1ll * vec[i].second;
            median = vec[i].first;
            i++;
        }

        return calc(nums, cost, median);
    }
};
