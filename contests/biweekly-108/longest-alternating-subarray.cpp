#include <math.h>
#include <vector>
using namespace std;

class Solution {
   public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        int tmp = -1;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] - nums[i] != -1)
                continue;
            tmp = 2;
            for (int j = i + 1; j < n; j++) {
                if (nums[j - 1] - nums[j] == -1 * pow(-1, j - i)) {
                    tmp++;
                    if(j == n - 1)
                        return max(ans, tmp);
                } else {
                    ans = max(ans, tmp);
                    break;
                }
            }
        }

        return max(ans, tmp);
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<int>> v = {{21, 22}, {2, 3, 4, 3, 4}, {4, 5, 6}};
    for (auto& i : v)
        auto result = Solution().alternatingSubarray(i);

    return 0;
}
