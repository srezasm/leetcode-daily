// 2023-07-10

/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (44.78%)
 * Likes:    6531
 * Dislikes: 1198
 * Total Accepted:    1M
 * Total Submissions: 2.2M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 *
 * Note: A leaf is a node with no children.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: root = [2,null,3,null,4,null,5,null,6]
 * Output: 5
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^5].
 * -1000 <= Node.val <= 1000
 *
 *
 */

#include <limits.h>
#include <queue>
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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        queue<TreeNode*> q;
        q.push(root);
        int i = 0;

        while (!q.empty()) {
            i++;
            int size = q.size();

            for (int j = 0; j < size; j++) {
                auto front = q.front();

                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);

                q.pop();

                if (front->left == nullptr && front->right == nullptr)
                    return i;
            }
        }

        return 0xA1D5;
    }
};
