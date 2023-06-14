// 2023-06-14
/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (57.22%)
 * Likes:    3404
 * Dislikes: 166
 * Total Accepted:    244.4K
 * Total Submissions: 419.3K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * Given the root of a Binary Search Tree (BST), return the minimum absolute
 * difference between the values of any two different nodes in the tree.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [4,2,6,1,3]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,0,48,null,null,12,49]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [2, 10^4].
 * 0 <= Node.val <= 10^5
 *
 *
 *
 * Note: This question is the same as 783:
 * https://leetcode.com/problems/minimum-distance-between-bst-nodes/
 *
 */

#include <limits.h>
#include <math.h>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int getResult(TreeNode* curr,
                  vector<TreeNode*> parents = {},
                  int ans = INT_MAX) {
        // Get the minimum absolute difference between the current node and its
        // parents
        for (const auto& c : parents)
            ans = min(ans, abs(curr->val - c->val));

        // Add current node to the parents list
        parents.push_back(curr);

        // Initialize the right and left subtrees answers with maximum value of
        // int
        int right_ans = INT_MAX;
        int left_ans = INT_MAX;

        // Recursively call function on left and right subtrees if they exist
        if (curr->left != nullptr)
            left_ans = getResult(curr->left, parents, ans);
        if (curr->right != nullptr)
            right_ans = getResult(curr->right, parents, ans);

        return min(min(right_ans, left_ans), ans);
    }

    int getMinimumDifference(TreeNode* root) { return getResult(root); }
};
