// 2023-07-24

/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (33.18%)
 * Likes:    8188
 * Dislikes: 8136
 * Total Accepted:    1.3M
 * Total Submissions: 3.9M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (i.e.,
 * x^n).
 *
 *
 * Example 1:
 *
 *
 * Input: x = 2.00000, n = 10
 * Output: 1024.00000
 *
 *
 * Example 2:
 *
 *
 * Input: x = 2.10000, n = 3
 * Output: 9.26100
 *
 *
 * Example 3:
 *
 *
 * Input: x = 2.00000, n = -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 *
 *
 *
 * Constraints:
 *
 *
 * -100.0 < x < 100.0
 * -2^31 <= n <= 2^31-1
 * n is an integer.
 * Either x is not zero or n > 0.
 * -10^4 <= x^n <= 10^4
 *
 *
 */

#include <math.h>
using namespace std;

class Solution {
   public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
        }

        long num = labs(n);

        double pow = 1;

        while (num) {
            if (num & 1) {
                pow *= x;
            }

            x *= x;
            num >>= 1;
        }

        return pow;
    }
};
