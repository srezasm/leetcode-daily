// 2023-06-30
// skipped

/*
 * @lc app=leetcode id=1979 lang=cpp
 *
 * [1979] Find Greatest Common Divisor of Array
 *
 * https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/
 *
 * algorithms
 * Easy (77.05%)
 * Likes:    904
 * Dislikes: 36
 * Total Accepted:    89.2K
 * Total Submissions: 115.7K
 * Testcase Example:  '[2,5,6,9,10]'
 *
 * Given an integer array nums, return the greatest common divisor of the
 * smallest number and largest number in nums.
 *
 * The greatest common divisor of two numbers is the largest positive integer
 * that evenly divides both numbers.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,5,6,9,10]
 * Output: 2
 * Explanation:
 * The smallest number in nums is 2.
 * The largest number in nums is 10.
 * The greatest common divisor of 2 and 10 is 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [7,5,6,8,3]
 * Output: 1
 * Explanation:
 * The smallest number in nums is 3.
 * The largest number in nums is 8.
 * The greatest common divisor of 3 and 8 is 1.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [3,3]
 * Output: 3
 * Explanation:
 * The smallest number in nums is 3.
 * The largest number in nums is 3.
 * The greatest common divisor of 3 and 3 is 3.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 1000
 * 1 <= nums[i] <= 1000
 *
 *
 */

#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isPossible(int m, int n, int t, vector<vector<int>>& cells) {
        vector<vector<int>> grid(m + 1, vector<int>(n + 1, 0));               // Grid representation
        vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};  // Possible directions

        for (int i = 0; i < t; i++) {
            grid[cells[i][0]][cells[i][1]] = 1;  // Mark cells from the given list as blocked
        }

        queue<pair<int, int>> q;

        for (int i = 1; i <= n; i++) {
            if (grid[1][i] == 0) {
                q.push({1, i});  // Start BFS from the top row
                grid[1][i] = 1;  // Mark the cell as visited
            }
        }
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int r = p.first, c = p.second;  // Current cell coordinates
            for (auto d : directions) {
                int nr = r + d.first, nc = c + d.second;  // Neighbor cell coordinates
                if (nr > 0 && nc > 0 && nr <= m && nc <= n && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1;  // Mark the neighbor cell as visited
                    if (nr == m) {
                        return true;  // Found a path to the bottom row
                    }
                    q.push({nr, nc});  // Add the neighbor cell to the queue for further exploration
                }
            }
        }
        return false;  // Unable to find a path to the bottom row
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 0, right = row * col, latestPossibleDay = 0;
        while (left < right - 1) {
            int mid = left + (right - left) / 2;  // Calculate the mid-day
            if (isPossible(row, col, mid, cells)) {
                left = mid;               // Update the left pointer to search in the upper half
                latestPossibleDay = mid;  // Update the latest possible day
            } else {
                right = mid;  // Update the right pointer to search in the lower half
            }
        }
        return latestPossibleDay;
    }
};
