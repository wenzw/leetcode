class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = height.size();
        int ret = 0;
        int* l = new int[size];
        int* r = new int[size];
        
        for (int i = 0; i < size; i++) {
            l[i] = i;
            while (l[i] > 0 && height[l[i] - 1] >= height[i]) l[i] = l[l[i] - 1];
        }
        
        for (int i = size - 1; i >= 0; i--) {
            r[i] = i;
            while (r[i] < size - 1 && height[r[i] + 1] >= height[i]) r[i] =  r[r[i] + 1];
        }
        
        for (int i = 0; i < size; i++) {
            int cur = (r[i] - l[i] + 1) * height[i];
            if (ret < cur) {
                ret = cur;
            }
        }
        delete l;
        delete r;
        return ret;
    }
};
