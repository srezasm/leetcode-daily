// 2023-07-11

/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 *
 * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
 *
 * algorithms
 * Medium (62.38%)
 * Likes:    9168
 * Dislikes: 176
 * Total Accepted:    330.1K
 * Total Submissions: 523.9K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n2'
 *
 * Given the root of a binary tree, the value of a target node target, and an
 * integer k, return an array of the values of all nodes that have a distance k
 * from the target node.
 *
 * You can return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
 * Output: [7,4,1]
 * Explanation: The nodes that are a distance 2 from the target node (with
 * value 5) have values 7, 4, and 1.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1], target = 1, k = 3
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 500].
 * 0 <= Node.val <= 500
 * All the values Node.val are unique.
 * target is the value of one of the nodes in the tree.
 * 0 <= k <= 1000
 *
 *
 */

#include <stddef.h>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<int, TreeNode*> upper_node;
        unordered_map<int, bool> visited;
        queue<TreeNode*> queue;

        queue.push(root);

        // fill the upper_node
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            if (current->left) {
                upper_node[current->left->val] = current;
                queue.push(current->left);
            }
            if (current->right) {
                upper_node[current->right->val] = current;
                queue.push(current->right);
            }
        }

        queue.push(target);
        visited[target->val] = true;
        int curr_level = 0;

        // go to k level from target
        while (!queue.empty()) {
            int size = queue.size();
            if (curr_level++ == K)
                break;
            for (int i = 0; i < size; i++) {
                TreeNode* current = queue.front();
                queue.pop();
                if (current->left && !visited[current->left->val]) {
                    queue.push(current->left);
                    visited[current->left->val] = true;
                }
                if (current->right && !visited[current->right->val]) {
                    queue.push(current->right);
                    visited[current->right->val] = true;
                }
                if (upper_node[current->val] && !visited[upper_node[current->val]->val]) {
                    queue.push(upper_node[current->val]);
                    visited[upper_node[current->val]->val] = true;
                }
            }
        }

        vector<int> result;
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            result.push_back(current->val);
        }
        return result;
    }
};

// // Think out of the box answer!
// // redefine the TreeNode!
// class Solution {
//    private:
//     struct Node {
//         int val;
//         Node* left;
//         Node* right;
//         Node* parent;
//         Node(TreeNode* analog, Node* _parent) {
//             if (analog->left == nullptr)
//                 left = nullptr;
//             else
//                 left = new Node(analog->left, this);

//             if (analog->right == nullptr)
//                 right = nullptr;
//             else
//                 right = new Node(analog->right, this);

//             parent = _parent;
//             val = analog->val;
//         }
//     };

//     struct LCounter  // Layer counter
//     {
//         int layer;
//         Node* node;
//         LCounter(Node* n, int l) {
//             node = n;
//             layer = l;
//         }
//     };

//    public:
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         Node* newRoot = new Node(root, nullptr);  // this copys TreeNode graph into
//                                                   // new  graph but with parent nodes too
//         vector<int> res;
//         Node* newTarget = GetTarget(target->val, newRoot);
//         cout << newTarget->val << endl;
//         Generate(newTarget, k, res);
//         return res;
//     }

//     Node* GetTarget(int val, Node* root) {
//         queue<Node*> Queue;
//         Queue.push(root);
//         Node* curr = nullptr;
//         while (!Queue.empty()) {
//             curr = Queue.front();
//             Queue.pop();
//             if (curr->val == val)
//                 return curr;
//             if (curr->left != nullptr)
//                 Queue.push(curr->left);
//             if (curr->right != nullptr)
//                 Queue.push(curr->right);
//         }
//         return nullptr;
//     }

//     void Generate(Node* startNode, int k, vector<int>& res) {
//         set<Node*> Seens;
//         queue<LCounter*> Queue;
//         LCounter* starter = new LCounter(startNode, 0);
//         Queue.push(starter);
//         Seens.insert(startNode);
//         LCounter* Curr = nullptr;
//         while (!Queue.empty()) {
//             Curr = Queue.front();
//             Queue.pop();
//             if (Curr->layer == k)
//                 res.push_back(Curr->node->val);
//             else {
//                 Add(Curr, Curr->node->parent, Seens, Queue);
//                 Add(Curr, Curr->node->left, Seens, Queue);
//                 Add(Curr, Curr->node->right, Seens, Queue);
//             }
//         }
//     }

//     void Add(LCounter* node, Node* child, set<Node*>& Seens, queue<LCounter*>& Queue) {
//         if (child == nullptr)
//             return;
//         if (Seens.find(child) != Seens.end())
//             return;
//         LCounter* newNode = new LCounter(child, node->layer + 1);
//         Queue.push(newNode);
//         Seens.insert(child);
//     }
// };