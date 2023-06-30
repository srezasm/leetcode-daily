// 2023-06-30

/*
 * @lc app=leetcode id=1502 lang=cpp
 *
 * [1502] Can Make Arithmetic Progression From Sequence
 *
 * https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/
 *
 * algorithms
 * Easy (70.42%)
 * Likes:    2010
 * Dislikes: 99
 * Total Accepted:    213.7K
 * Total Submissions: 304.4K
 * Testcase Example:  '[3,5,1]'
 *
 * A sequence of numbers is called an arithmetic progression if the difference
 * between any two consecutive elements is the same.
 *
 * Given an array of numbers arr, return true if the array can be rearranged to
 * form an arithmetic progression. Otherwise, return false.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [3,5,1]
 * Output: true
 * Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with
 * differences 2 and -2 respectively, between each consecutive elements.
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [1,2,4]
 * Output: false
 * Explanation: There is no way to reorder the elements to obtain an arithmetic
 * progression.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= arr.length <= 1000
 * -10^6 <= arr[i] <= 10^6
 *
 *
 */

#include <limits.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        priority_queue<int> q(begin(arr), end(arr));

        int tmp = q.top();
        q.pop();
        int diff = tmp - q.top();
        tmp = q.top();
        q.pop();

        for (int i = 0; i < n - 2; i++) {
            if(tmp - q.top() != diff)
                return false;
            tmp = q.top();
            q.pop();
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v = {3, 5, 1};
    Solution().canMakeArithmeticProgression(v);
    return 0;
}

