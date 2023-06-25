// 2023-06-25

/*
 * @lc app=leetcode id=781 lang=cpp
 *
 * [781] Rabbits in Forest
 *
 * https://leetcode.com/problems/rabbits-in-forest/description/
 *
 * algorithms
 * Medium (54.47%)
 * Likes:    1097
 * Dislikes: 557
 * Total Accepted:    47.7K
 * Total Submissions: 87.6K
 * Testcase Example:  '[1,1,2]'
 *
 * There is a forest with an unknown number of rabbits. We asked n rabbits "How
 * many rabbits have the same color as you?" and collected the answers in an
 * integer array answers where answers[i] is the answer of the i^th rabbit.
 *
 * Given the array answers, return the minimum number of rabbits that could be
 * in the forest.
 *
 *
 * Example 1:
 *
 *
 * Input: answers = [1,1,2]
 * Output: 5
 * Explanation:
 * The two rabbits that answered "1" could both be the same color, say red.
 * The rabbit that answered "2" can't be red or the answers would be
 * inconsistent.
 * Say the rabbit that answered "2" was blue.
 * Then there should be 2 other blue rabbits in the forest that didn't answer
 * into the array.
 * The smallest possible number of rabbits in the forest is therefore 5: 3 that
 * answered plus 2 that didn't.
 *
 *
 * Example 2:
 *
 *
 * Input: answers = [10,10,10]
 * Output: 11
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= answers.length <= 1000
 * 0 <= answers[i] < 1000
 *
 *
 */

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    int numRabbits(vector<int>& a) {
        sort(begin(a), end(a));
        a.push_back(0);

        int n = a.size();

        int count = 1;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) {
                int val = a[i - 1] + 1;
                ans += (count / val) * val;
                if (count % val != 0)
                    ans += val;

                count = 1;
            } else
                count++;
        }

        return ans;
    }
};
