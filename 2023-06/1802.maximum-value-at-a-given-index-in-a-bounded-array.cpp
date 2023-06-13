class Solution {
   public:
    unsigned long long triangularsum(int n, int index, int k) {
        long leftheight = k - index - 1;
        long rightheight = k - n + index;
        if (leftheight < 0)
            leftheight = 0;
        if (rightheight < 0)
            rightheight = 0;
        unsigned long long left =
            (long)k * (k + 1) / 2 - ((long)leftheight) * (leftheight + 1) / 2;
        unsigned long long right =
            (long)k * (k + 1) / 2 - ((long)rightheight) * (rightheight + 1) / 2;
        return left + right - k + n;
    }

    int maxValue(int n, int index, int maxSum) {
        int hi = 2 * maxSum;
        int lo = 0;
        long long md, tsum;
        while (lo <= hi) {
            md = (hi + lo) / 2;
            tsum = triangularsum(n, index, md);
            if (tsum < maxSum) {
                lo = md + 1;
            } else if (tsum > maxSum) {
                hi = md - 1;
            }
            if (tsum == maxSum) {
                return md + 1;
            }
        }
        return hi + 1;
    }
};