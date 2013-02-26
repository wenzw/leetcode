class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (!isAlphanumeric(s[i])) {
                i++;
                continue;
            }
            if (!isAlphanumeric(s[j])) {
                j--;
                continue;
            }
            
            if (toLower(s[i]) == toLower(s[j])) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
    
    bool isAlphanumeric(char c) {
        if (c <= '9' && c >= '0') return true;
        if (c <= 'Z' && c >= 'A') return true;
        if (c <= 'z' && c >= 'a') return true;
        return false;
    }
    
    char toLower(char c) {
        if (c <= 'Z' && c >= 'A') return 'a' + c - 'A';
        return c;
    }
};
