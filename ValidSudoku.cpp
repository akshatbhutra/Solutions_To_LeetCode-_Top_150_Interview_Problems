// Approach:
// Check for 3 Validations: rowWise, columnWise, MatrixWise
class Solution {
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ok1 = 1, ok2 = 1, ok3 = 1;
        
        for (int i = 0; i < 9; i++) {
            set<char> s;
            int c = 0;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') 
                    c++;
                else s.insert(board[i][j]);
            }
            if (9 - c != (int)s.size()) {
                ok1 = 0;
                break;
            }
        }
                
        for (int i = 0; i < 9; i++) {
            set<char> s;
            int c = 0;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') 
                    c++;
                else s.insert(board[j][i]);
            }
            if (9 - c != (int) s.size()) {
                ok2 = 0;
                break;
            }
        }
                
        for (int i = 0; i < 9; i += 3) {
            set<char> s;
            int ct = 0;
            for (int r = i; r <= i + 2; r++) {
                for (int c = 0; c <= 2; c++) {
                    if (board[r][c] == '.') ct++;
                    else s.insert(board[r][c]);
                }
            }
            if (9 - ct != (int) s.size()) {
                ok3 = 0;
                break;
            }
            ct = 0;
            set<char> s2;
            for (int r = i; r <= i + 2; r++) {
                for (int c = 3; c <= 5; c++) {
                    if (board[r][c] == '.') ct++;
                    else s2.insert(board[r][c]);
                }
            }
            if (9 - ct != (int) s2.size()) {
                ok3 = 0;
                break;
            }
             ct = 0;
            set<char> s3;
            for (int r = i; r <= i + 2; r++) {
                for (int c = 6; c <= 8; c++) {
                    if (board[r][c] == '.') ct++;
                    else s3.insert(board[r][c]);
                }
            }
            if (9 - ct != (int) s3.size()) {
                ok3 = 0;
                break;
            }
        }  
        return (ok1 && ok2 && ok3);   
    }
};