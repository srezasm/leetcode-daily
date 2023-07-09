#include <vector>
#include <limits.h>
using namespace std;

class Solution {
   public:
    int solve(vector<int>& nums, int target, int cur, int ans, int n) {
        if (cur == n - 1)
            return ans;
        
        for (int i = cur; i < n; i++) {
            if (target <= i - cur || i - cur <= target) {
                ans = max(ans, solve(nums, target, i, ans + 1, n));
            }
        }

        return ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        return max(solve(nums, target, 0, INT_MIN, nums.size()), -1);
    }
};