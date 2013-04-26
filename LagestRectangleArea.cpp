class Solution {
public:
    int largestRectangleArea2(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max = 0;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] > max) {
                max = height[i];
            }
        }
        if (max > height.size()) {
            return largestRectangleArea3(height);
        }
        int bs = sizeof(int) * max;
        int* a[2];
        a[0] = new int[max];
        //memset(a[0], 0, bs);
        a[1] = new int[max];
        memset(a[1], 0, bs);
        
        int r = 0;
        int cur = 1;
        int pre = 1 - cur;
        for (int i = 0; i < height.size(); i++) {
            pre = cur;
            cur = 1 - pre;
            memset(a[cur], 0, bs);
            for (int j = 0; j < height[i]; j++) {
                a[cur][j] = a[pre][j] + j + 1;
                if (r < a[cur][j]) {
                    r = a[cur][j];
                }
            }
        }
        delete a[0];
        delete a[1];
        return r;
    }
    
    int largestRectangleArea3(vector<int> &height) {
        int r = 0;
        int bs = sizeof(int) * height.size();
        int* a[2];
        a[0] = new int[height.size()];
        a[1] = new int[height.size()];
        for (int i = 0; i < height.size(); i++) {
            a[1][i] = height[i];
            if (r < height[i]) {
                r = height[i];
            }
        }
        
        int cur = 1;
        int pre = 1 - cur;
        for (int k = 1; k < height.size(); k++) {
            pre = cur;
            cur = 1 - pre;
            memset(a[cur], 0, bs);
            for (int i = 0; i < height.size() - k; i++) {
                a[cur][i] = min(a[pre][i], a[pre][i+1]);
                int curmax = a[cur][i] * (k + 1);
                if (r < curmax) {
                    r = curmax;
                }
            }
        }
        delete a[0];
        delete a[1];
        return r;
    }
    
    int largestRectangleArea4(vector<int> &height) {
        int r = 0;
        for (int i = 0; i < height.size(); i++) {
            if (r < height[i]) {
                r = height[i];
            }
        }
        for (int k = 1; k < height.size(); k++) {
            for (int i = 0; i < height.size() - k; i++) {
                height[i] = min(height[i], height[i+1]);
                int cur = height[i] * (k + 1);
                if (r < cur) {
                    r = cur;
                }
            }
        }
        return r;
    }
    
    int largestRectangleArea(vector<int> &height) {
        int ret = 0;
        int size = height.size();
        int* l = new int[size];
        int* r = new int[size];
        for (int i = 0; i < height.size(); i++) {
            l[i] = i;
            while (l[i] > 0 && height[i] <= height[l[i]-1]) l[i] = l[l[i] - 1];
        }
        for (int i = size-1; i>= 0; i--) {
            r[i] = i;
            while (r[i] < size - 1 && height[i] <= height[r[i]+1]) r[i] = r[r[i] + 1];
        }
        for (int i = 0; i < size; i++) {
            int cur = (r[i] - l[i] + 1) * height[i];
            if (ret < cur) ret = cur;
        }
        delete l;
        delete r;
        return ret;
    }
};
