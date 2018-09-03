class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        const int mark = 0b111111111;
        vector<int> R(9, mark), C(9, mark);
        vector<vector<int>> Z(3, vector<int> (3, mark));
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                int zr = i/3, zc = j/3;
                if (board[i][j] != '.'){
                    int bit = 1<<(board[i][j]-'1');
                    R[i] ^= bit;
                    C[j] ^= bit;
                    Z[zr][zc] ^= bit;
                }
            }
        }
        int nSol = mySolver(board, 0, R, C, Z);
        return;
    }
private:
    int mySolver(vector<vector<char>>& board, int pos, vector<int>& R, vector<int>& C, vector<vector<int>>& Z){
        if (pos >= 81) return 1;
        int row = pos/9, col = pos%9, zr = row/3, zc = col/3;
        if (board[row][col] != '.') return mySolver(board, pos+1, R, C, Z);
        else {
            int valid = R[row] & C[col] & Z[zr][zc];
            while (valid != 0){
                int next = valid & -valid;
                valid ^= next;
                R[row] ^= next, C[col] ^= next, Z[zr][zc] ^= next;
                if (mySolver(board, pos+1, R, C, Z)){
                    board[row][col] = bit2char(next);
                    return 1;
                }
                R[row] ^= next, C[col] ^= next, Z[zr][zc] ^= next;
            }
            return 0;
        }
    }
    char bit2char(int x){
        int k=0;
        while (x!=0){
            x >>= 1;
            k++;
        }
        return k + '0';
    }
};
