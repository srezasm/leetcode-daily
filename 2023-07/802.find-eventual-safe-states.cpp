// 2023-07-12

/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 *
 * https://leetcode.com/problems/find-eventual-safe-states/description/
 *
 * algorithms
 * Medium (57.41%)
 * Likes:    4957
 * Dislikes: 423
 * Total Accepted:    190.6K
 * Total Submissions: 311.9K
 * Testcase Example:  '[[1,2],[2,3],[5],[0],[5],[],[]]'
 *
 * There is a directed graph of n nodes with each node labeled from 0 to n - 1.
 * The graph is represented by a 0-indexed 2D integer array graph where
 * graph[i] is an integer array of nodes adjacent to node i, meaning there is
 * an edge from node i to each node in graph[i].
 *
 * A node is a terminal node if there are no outgoing edges. A node is a safe
 * node if every possible path starting from that node leads to a terminal node
 * (or another safe node).
 *
 * Return an array containing all the safe nodes of the graph. The answer
 * should be sorted in ascending order.
 *
 *
 * Example 1:
 *
 *
 * Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
 * Output: [2,4,5,6]
 * Explanation: The given graph is shown above.
 * Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either
 * of them.
 * Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
 *
 * Example 2:
 *
 *
 * Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
 * Output: [4]
 * Explanation:
 * Only node 4 is a terminal node, and every path starting at node 4 leads to
 * node 4.
 *
 *
 *
 * Constraints:
 *
 *
 * n == graph.length
 * 1 <= n <= 10^4
 * 0 <= graph[i].length <= n
 * 0 <= graph[i][j] <= n - 1
 * graph[i] is sorted in a strictly increasing order.
 * The graph may contain self-loops.
 * The number of edges in the graph will be in the range [1, 4 * 10^4].
 *
 *
 */

#include <vector>
using namespace std;

class Solution {
   public:
    bool dfs(vector<vector<int>>& adj, int src, vector<bool>& vis, vector<bool>& recst) {
        vis[src] = true;
        recst[src] = true;
        for (auto x : adj[src]) {
            if (vis[x] == false && dfs(adj, x, vis, recst)) {
                return true;
            } else if (recst[x] == true) {
                return true;
            }
        }
        recst[src] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<bool> vis(n, false);
        vector<bool> recst(n, false);
        for (int i = 0; i < n; i++) {
            if (vis[i] == false) {
                dfs(adj, i, vis, recst);
            }
        }
        vector<int> ans;
        for (int i = 0; i < recst.size(); i++) {
            if (!recst[i])
                ans.push_back(i);
        }
        return ans;
    }
};
