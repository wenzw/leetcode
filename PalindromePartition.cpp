class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string>> vvs;
        if (s.empty()) return vvs;
        for (int i = s.length() - 1; i >= 0; i--) {
            string tail = s.substr(i);
            if (isPalindrome(tail)) {
                string head = s.substr(0, i);
                if (head.empty()) {
                    vector<string> vs;
                    vs.push_back(tail);
                    vvs.push_back(vs);
                    continue;
                }
                vector<vector<string>> tvvs = partition(s.substr(0, i));
                for (int j = 0; j < tvvs.size(); j++) {
                    tvvs[j].push_back(tail);
                    vvs.push_back(tvvs[j]);
                }
            }
        }
        return vvs;
    }
    
    bool isPalindrome(string s) {
        if (s.length() <= 1) return true;
        int b = 0;
        int e = s.length() - 1;
        while (b <= e) {
            if (s[b] != s[e]) {
                return false;
            }
            b++;
            e--;
        }
        return true;
    }
};
