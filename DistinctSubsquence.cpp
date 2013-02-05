class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (S.length() < T.length()) {
            return 0;
        }
        if (S.empty()) {
            return 0;
        }
        if (T.length() == 1) {
            int n = 0;
            for (int i = 0; i < S.length(); i++) {
                if (S[i] == T[0]) n++;
            }
            return n;
        }
        // dp
        int** cnt = new int*[2];
        cnt[0] = new int[T.length() + 1];
        memset(cnt[0], 0, sizeof(int) * (T.length() + 1));
        cnt[1] = new int[T.length() + 1];
        memset(cnt[1], 0, sizeof(int) * (T.length() + 1));
        
        int p = 0;
        for (int i = 0; i < S.length(); i++)
        {
            cnt[1-p][0] = 1;
            for (int j = 0; j < min(T.length(), (unsigned int)i + 1); j++)
            {
                if (S[i] == T[j])
                {
                    cnt[p][j+1] = cnt[1-p][j+1] + cnt[1-p][j];
                }
                else
                {
                    cnt[p][j+1] = cnt[1-p][j+1];
                }
            }
            p = 1 - p;
        }
        return cnt[1-p][T.length()];
    }
    
};
