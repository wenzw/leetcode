class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxprofile = 0;
        int min = 0x7FFFFFFF;
        int max = 0;
        vector<int>::iterator it = prices.begin();
        for (; it != prices.end(); it++)
        {
            int cur = *it;
            if (cur < min)
            {
                min = cur;
                max = cur;
            }
            if (cur > max) max = cur;
            int p = max - min;
            if (p > maxprofile) maxprofile = p;
        }
        return maxprofile;
    }
};
