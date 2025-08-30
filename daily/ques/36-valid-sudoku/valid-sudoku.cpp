class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<int, 9> row{}; 
        array<int, 9> col{}; 
        array<int, 9> box{};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char ch = board[r][c];
                if (ch == '.') continue;
                int d = ch - '1';           // 0..8
                int bit = 1 << d;
                int b = (r / 3) * 3 + (c / 3);
                if ((row[r] & bit) || (col[c] & bit) || (box[b] & bit)) return false;
                row[r] |= bit;
                col[c] |= bit;
                box[b] |= bit;
            }
        }
        return true;
    }
};
