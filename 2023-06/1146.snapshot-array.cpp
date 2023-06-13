#include <map>
#include <vector>
using namespace std;

class SnapshotArray {
   public:
    vector<vector<pair<int, int>>> v;
    int count = 0;
    SnapshotArray(int length) {
        v = vector<vector<pair<int, int>>>(length,
                                           vector<pair<int, int>>(1, {0, 0}));
    }

    void set(int index, int val) {
        int n = v[index].size();
        if (v[index][n - 1].second == count)
            v[index][n - 1].first = val;
        else
            v[index].push_back({val, count});
    }

    int snap() {
        count++;
        return count - 1;
    }

    int get(int index, int snap_id) {
        int l = 0, r = v[index].size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (v[index][mid].second == snap_id) {
                return v[index][mid].first;
            }
            if (v[index][mid].second > snap_id)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return v[index][r].first;
    }
};