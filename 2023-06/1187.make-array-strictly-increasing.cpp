// 2023-06-17
/*
 * @lc app=leetcode id=1187 lang=cpp
 *
 * [1187] Make Array Strictly Increasing
 *
 * https://leetcode.com/problems/make-array-strictly-increasing/description/
 *
 * algorithms
 * Hard (45.60%)
 * Likes:    1606
 * Dislikes: 29
 * Total Accepted:    33.5K
 * Total Submissions: 60K
 * Testcase Example:  '[1,5,3,6,7]\n[1,3,2,4]'
 *
 * Given two integer arrays arr1 and arr2, return the minimum number of
 * operations (possibly zero) needed to make arr1 strictly increasing.
 *
 * In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j
 * < arr2.length and do the assignment arr1[i] = arr2[j].
 *
 * If there is no way to make arr1 strictly increasing, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
 * Output: 1
 * Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
 *
 *
 * Example 2:
 *
 *
 * Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
 * Output: 2
 * Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6,
 * 7].
 *
 *
 * Example 3:
 *
 *
 * Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
 * Output: -1
 * Explanation: You can't make arr1 strictly increasing.
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr1.length, arr2.length <= 2000
 * 0 <= arr1[i], arr2[i] <= 10^9
 *
 *
 *
 */

#include <limits.h>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        arr1.push_back(INT_MAX);
        sort(begin(arr2), end(arr2));
        arr2.erase(unique(begin(arr2), end(arr2)), end(arr2));
        int n = arr1.size(), f[n];
        for (int i = 0; i < n; ++i) {
            int k =
                lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
            int res = k < i ? INT_MIN : 0;
            if (i > 0 && arr1[i - 1] < arr1[i]) {
                res = max(res, f[i - 1]);
            }
            for (int j = i - 2; j > i - k - 1 && j >= 0; --j) {
                if (arr2[k - (i - j - 1)] > arr1[j]) {
                    res = max(res, f[j]);
                }
            }
            f[i] = res + 1;
        }
        return f[n - 1] < 0 ? -1 : n - f[n - 1];
    }
};
