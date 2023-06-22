// 2023-06-22

/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
 *
 * algorithms
 * Medium (65.57%)
 * Likes:    5839
 * Dislikes: 152
 * Total Accepted:    255.5K
 * Total Submissions: 384.4K
 * Testcase Example:  '[1,3,2,8,4,9]\n2'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day, and an integer fee representing a transaction fee.
 *
 * Find the maximum profit you can achieve. You may complete as many
 * transactions as you like, but you need to pay the transaction fee for each
 * transaction.
 *
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 *
 *
 * Example 1:
 *
 *
 * Input: prices = [1,3,2,8,4,9], fee = 2
 * Output: 8
 * Explanation: The maximum profit can be achieved by:
 * - Buying at prices[0] = 1
 * - Selling at prices[3] = 8
 * - Buying at prices[4] = 4
 * - Selling at prices[5] = 9
 * The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
 *
 *
 * Example 2:
 *
 *
 * Input: prices = [1,3,7,5,10,3], fee = 3
 * Output: 6
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= prices.length <= 5 * 10^4
 * 1 <= prices[i] < 5 * 10^4
 * 0 <= fee < 5 * 10^4
 *
 *
 */

#include <iostream>
#include <vector>
using namespace std;

static int _ = []() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int hold = -prices[0];
        int free = 0;

        for (int i = 1; i < n; i++) {
            int tmp = hold;
            hold = max(hold, free - prices[i]);
            free = max(free, tmp + prices[i] - fee);
        }

        return free;
    }
};
