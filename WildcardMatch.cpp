class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s == NULL || p == NULL) return false;
        int ls = strlen(s);
        int lp = strlen(p);
        int alphaInp = 0;
        for (int i = 0; i < lp; i++) {
            if (p[i] != '*' && p[i] != '?') {
                alphaInp++;
            }
        }
        if (alphaInp > ls) return false;
        bool** m = new bool*[2];
        m[0] = new bool[ls + 1];
        memset(m[0], 0, sizeof(bool) * (ls+1));
        m[1] = new bool[ls + 1];
        memset(m[1], 0, sizeof(bool) * (ls+1));
        m[0][0] = true;
        int pos = 0;
        for (int i = 0; i < lp; i++) {
            pos = 1 - pos;
            if (p[i] == '*') {
                m[pos][0] = m[1-pos][0];
            } else {
                m[pos][0] = false;
            }

            for (int j = 0; j < ls; j++) {
                if (p[i] == s[j] || p[i] == '?') {
                    m[pos][j + 1] = m[1 - pos][j];
                } else if (p[i] == '*') {
                    m[pos][j + 1] = m[1 - pos][j] || m[1 - pos][j + 1] || m[pos][j];
                } else {
                    m[pos][j + 1] = false;
                }
            }

        }
        return m[pos][ls];
    }
};
