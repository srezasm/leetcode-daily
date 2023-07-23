// 2023-07-24

/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
 *
 * https://leetcode.com/problems/all-possible-full-binary-trees/description/
 *
 * algorithms
 * Medium (79.95%)
 * Likes:    4613
 * Dislikes: 307
 * Total Accepted:    153.3K
 * Total Submissions: 185.3K
 * Testcase Example:  '7'
 *
 * Given an integer n, return a list of all possible full binary trees with n
 * nodes. Each node of each tree in the answer must have Node.val == 0.
 *
 * Each element of the answer is the root node of one possible tree. You may
 * return the final list of trees in any order.
 *
 * A full binary tree is a binary tree where each node has exactly 0 or 2
 * children.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 7
 * Output:
 * [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3
 * Output: [[0,0,0]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 20
 *
 *
 */

#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    unordered_map<int, vector<TreeNode*>> m;
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        if (m.find(n) != m.end()) {
            return m[n];
        }
        if (n == 1) {
            TreeNode* temp = new TreeNode(0);
            ans.push_back(temp);
            return ans;
        }
        if (n % 2) {
            for (int i = 0; i < n; i++) {
                int left = i;
                int right = n - i - 1;
                vector<TreeNode*> l = allPossibleFBT(i);
                vector<TreeNode*> r = allPossibleFBT(right);
                for (auto x : l) {
                    for (auto y : r) {
                        TreeNode* temp = new TreeNode(0);
                        temp->left = x;
                        temp->right = y;
                        ans.push_back(temp);
                    }
                }
            }
            m[n] = ans;
        }
        return ans;
    }
};
