// 2023-06-13 1821-2015

#include <vector>
using namespace std;

class Solution {
   public:
    int equalPairs(vector<vector<int>>& grid) {
        int size = grid.size();
        int ans = 0, z, k;
        for (int i = 0; i < size; i++) {
            z = 0;
            k = 0;
            while (z <= size - 1) {
                if(i == 1 && z == 1)
                    int x = 12;
                if (k == size - 1 && grid[i][k] == grid[k][z]) {
                    ans++;
                    z++;
                    k = 0;
                    continue;
                }
                if (grid[i][k] == grid[k][z]) {
                    k++;
                } else {
                    z++;
                    k = 0;
                }
            }
        }
        return ans;
    }
};
