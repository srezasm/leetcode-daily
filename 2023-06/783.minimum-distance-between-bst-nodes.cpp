// 2023-06-14
/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
 *
 * https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
 *
 * algorithms
 * Easy (59.28%)
 * Likes:    3171
 * Dislikes: 391
 * Total Accepted:    217.4K
 * Total Submissions: 366K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * Given the root of a Binary Search Tree (BST), return the minimum difference
 * between the values of any two different nodes in the tree.
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
 * The number of nodes in the tree is in the range [2, 100].
 * 0 <= Node.val <= 10^5
 *
 *
 *
 * Note: This question is the same as 530:
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/
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

    int minDiffInBST(TreeNode* root) { return getResult(root); }
};
