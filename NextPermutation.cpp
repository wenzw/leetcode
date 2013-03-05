#define MIN -0x7FFFFFFF

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() <= 1) return;
        int last = MIN;
        int i;
        for (i = num.size() - 1; i >= 0; i--) {
            if (num[i] <  last) {
                break;
            }
            last = num[i];
        }
        if (i < 0) {
            reverse(num, 0, num.size() - 1);
            return;
        }
        int j = 0;
        for (j = num.size() - 1; j > i; j--) {
            if (num[j] > num[i]) {
                break;
            }
        }
        int tmp = num[i];
        num[i] = num[j];
        num[j] = tmp;
        reverse(num, i+1, num.size() - 1);
        return;
    }
    
    void reverse(vector<int> &num, int low, int high) {
        while (low < high) {
            int tmp = num[low];
            num[low] = num[high];
            num[high] = tmp;
            low++;
            high--;
        }
    }
};
