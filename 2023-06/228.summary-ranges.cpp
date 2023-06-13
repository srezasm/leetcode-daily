#include <vector>
#include <string>
using namespace std;

class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int len = size(nums);
        for(auto p(0), q(0); q < len; ++q) {
            if(q + 1 == len || nums[q + 1] != nums[q] + 1) {
                ans.push_back(nums[p] == nums[q] ? to_string(nums[p]) : to_string(nums[p]) + "->" + to_string(nums[q]));
                p = q + 1;
            }
        }
        return ans;
    }
};