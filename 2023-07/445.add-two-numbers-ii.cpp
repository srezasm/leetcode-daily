// 2023-07-17

/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (59.69%)
 * Likes:    5485
 * Dislikes: 270
 * Total Accepted:    429.5K
 * Total Submissions: 704.5K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 *
 * Example 1:
 *
 *
 * Input: l1 = [7,2,4,3], l2 = [5,6,4]
 * Output: [7,8,0,7]
 *
 *
 * Example 2:
 *
 *
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [8,0,7]
 *
 *
 * Example 3:
 *
 *
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
 *
 *
 *
 * Follow up: Could you solve it without reversing the input lists?
 *
 */

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0, n2 = 0, carry = 0;
        ListNode *curr1 = l1, *curr2 = l2, *res = NULL;
        while (curr1) {
            curr1 = curr1->next;
            n1++;
        }
        while (curr2) {
            curr2 = curr2->next;
            n2++;
        }
        curr1 = l1;
        curr2 = l2;
        while (n1 > 0 && n2 > 0) {
            int sum = 0;
            if (n1 >= n2) {
                sum += curr1->val;
                curr1 = curr1->next;
                n1--;
            }
            if (n2 > n1) {
                sum += curr2->val;
                curr2 = curr2->next;
                n2--;
            }
            res = addToFront(sum, res);
        }
        curr1 = res;
        res = NULL;
        while (curr1) {
            curr1->val += carry;
            carry = curr1->val / 10;
            res = addToFront(curr1->val % 10, res);
            curr2 = curr1;
            curr1 = curr1->next;
            delete curr2;
        }
        if (carry)
            res = addToFront(1, res);
        return res;
    }
    ListNode* addToFront(int val, ListNode* head) {
        ListNode* temp = new ListNode(val);
        temp->next = head;
        return temp;
    }
};
