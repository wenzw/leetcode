class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> r;
        if (rowIndex == 0) {
            r.push_back(1);
            return r;
        }   
            
        int len = rowIndex + 1;
        r.reserve(len);
        for (int i = 0; i < len; i++) {
            r.push_back(1);
        }
        int midlen;
        bool flag = true;
        for (int i = 1; i <= rowIndex; i++) {
            midlen = (i + 2) / 2;
            if (flag) { 
                r[0] = 1; 
                for (int j = 1; j < midlen; j++) {
                    r[j] = r[len - 1 - j] + r[len - j];
                }
            } else {
                r[len - 1] = 1;
                for (int j = len - 2; j >= len - midlen; j--) {
                    r[j] = r[len - j - 2] + r[len - j - 1];
                }
            }
            if (flag) {
                for (int j = len - 1; j >= midlen; j--) {
                    r[j] = r[len - 1 - j];
                }
            } else {
                for (int j = 0; j < midlen; j++) {
                    r[j] = r[len - 1 - j];
                }
            }
            for (int j = midlen; j < len - midlen; j++) {
                r[j] = r[midlen - 1];
            }   
            flag = !flag;
        }   
        
        return r;

    }
};
