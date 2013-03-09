class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (board.size() <= 1) return;
        if (board[0].size() <= 1) return;
        queue<pair<int, int> > q;
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < col; i++) {
            if (board[0][i] == 'O') {
                q.push(make_pair(0, i));
                board[0][i] = 'o';
            }
            if (board[row - 1][i] == 'O') {
                q.push(make_pair(row-1, i));
                board[row - 1][i] = 'o';
            }
        }
        
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O') {
                q.push(make_pair(i, 0));
                board[i][0] = 'o';
            }
            if (board[i][col - 1] == 'O') {
                q.push(make_pair(i, col-1));
                board[i][col - 1] = 'o';
            }
        }
        
        while (!q.empty()) {
            pair<int, int> cp = q.front();
            q.pop();
            if (cp.first > 0 && board[cp.first - 1][cp.second] == 'O') {
                q.push(make_pair(cp.first - 1, cp.second));
                board[cp.first - 1][cp.second] = 'o';
            } 
            if (cp.first < row - 1 && board[cp.first + 1][cp.second] == 'O') {
                q.push(make_pair(cp.first + 1, cp.second));
                board[cp.first + 1][cp.second] = 'o';
            } 
            if (cp.second > 0 && board[cp.first][cp.second - 1] == 'O') {
                q.push(make_pair(cp.first, cp.second - 1));
                board[cp.first][cp.second - 1] = 'o';
            }
            if (cp.second < col - 1 && board[cp.first][cp.second + 1] == 'O') {
                q.push(make_pair(cp.first, cp.second + 1));
                board[cp.first][cp.second + 1] = 'o';
            }
        }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'o') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
