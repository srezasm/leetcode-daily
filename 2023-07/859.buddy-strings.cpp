// 2023-07-03

/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 *
 * https://leetcode.com/problems/buddy-strings/description/
 *
 * algorithms
 * Easy (29.21%)
 * Likes:    2486
 * Dislikes: 1489
 * Total Accepted:    183.8K
 * Total Submissions: 581.6K
 * Testcase Example:  '"ab"\n"ba"'
 *
 * Given two strings s and goal, return true if you can swap two letters in s
 * so the result is equal to goal, otherwise, return false.
 *
 * Swapping letters is defined as taking two indices i and j (0-indexed) such
 * that i != j and swapping the characters at s[i] and s[j].
 *
 *
 * For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "ab", goal = "ba"
 * Output: true
 * Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is
 * equal to goal.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "ab", goal = "ab"
 * Output: false
 * Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b',
 * which results in "ba" != goal.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "aa", goal = "aa"
 * Output: true
 * Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is
 * equal to goal.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, goal.length <= 2 * 10^4
 * s and goal consist of lowercase letters.
 *
 *
 */

#include <map>
#include <string>
using namespace std;

class Solution {
   public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();

        if (n == 1)
            return false;

        if (s == goal) {
            map<int, int> map;
            for (auto const& c : s) {
                map[c]++;
                if (map[c] > 1)
                    return true;
            }
        }

        int k = 2;
        int a = -1, b;
        for (int i = 0; i < n; i++) {
            if (k == 0)
                break;
            if (s[i] != goal[i]) {
                if (a == -1)
                    a = i;
                else
                    b = i;
                k--;
            }
        }

        if (k > 0)
            return false;

        swap(s[a], s[b]);
        return goal == s;
    }
};
