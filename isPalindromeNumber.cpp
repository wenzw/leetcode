class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0) return false;
        int y = 0;
        int t = x;
        while (t > 0) {
            int b = t % 10;
            y = y * 10 + b;
            t = t / 10;
        }
        if (y == x) return true;
        return false;
    }
};
